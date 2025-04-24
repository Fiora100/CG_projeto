#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matriz3x3.h"
#include <QList>
#include <QString>
#include <QDebug>

static std::vector<float> fazerPonto(float x, float y) {
    return { x, y, 1.0f };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , contador(0)
    , contadorLinha(0)
{
    ui->setupUi(this);
    canvas = ui->canvas;
    canvas->setMainWindow(this); //ponteiro da janela principal
    configuraUi();
}

void MainWindow::configuraUi(){
    configuraSelectBox();
    configuraTabela();
    configuraFormasBase();
    configuraSlots();
}

void MainWindow::configuraSelectBox(){
    listaObjetos = { "Ponto", "Linha", "Triangulo", "Quadrado" , "Pentagono"};
    ui->selectBox->addItems(listaObjetos);
}

void MainWindow::configuraFormasBase(){
    QList<QList<std::vector<float>>> pontosFormas = {
        { fazerPonto(this->width()/2, this->height()/2) },                  // Ponto
        { fazerPonto(60.0f, 30.0f), fazerPonto(90.0f, 30.0f) },                             // Linha
        { fazerPonto(30.0f, 90.0f), fazerPonto(110.0f, 90.0f), fazerPonto(50.0f, 30.0f) },            // Triângulo
        { fazerPonto(10.0f, 90.0f), fazerPonto(90.0f, 90.0f), fazerPonto(90.0f, 10.0f), fazerPonto(10.0f, 10.0f) },                 // Quadrado
        { fazerPonto(60.0f, 20.0f), fazerPonto(90.0f, 45.0f), fazerPonto(80.0f, 85.0f), fazerPonto(40.0f, 85.0f), fazerPonto(30.0f, 45.0f) }  // Pentagono
    };

    for (int i = 0; i < listaObjetos.size(); ++i) {
        formasBase.append(formaGeometrica(pontosFormas[i], listaObjetos[i]));
    }
}

void MainWindow::configuraTabela(){
    ui->tabela->setColumnCount(2);
    ui->tabela->setHorizontalHeaderLabels(QStringList() << "Nome" << "ID");
    ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tabela->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabela->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::configuraSlots(){
    connect(ui->genButton, &QPushButton::clicked, canvas, &DrawArea::genDrawing);
    connect(ui->genButton, &QPushButton::clicked, this, &MainWindow::adicionarFormaTabela);
    connect(ui->delButton, &QPushButton::clicked, canvas, &DrawArea::genDrawing);
    connect(ui->delButton, &QPushButton::clicked, this, &MainWindow::removerFormaSelecionada);
}

void MainWindow::adicionarFormaTabela() {
    int i = getIndiceAtual();
    QList<std::vector<float>> pontosOriginais = formasBase[i].getPontos();
    float dx = ui->Dx->text().toFloat();
    float dy = ui->Dy->text().toFloat();
    float sx = ui->Sx->text().toFloat();
    float sy = ui->Sy->text().toFloat();
    float angulo = ui->Rota->text().toFloat();
    Matriz3x3 Trans = Matriz3x3::Translada(dx, dy);
    Matriz3x3 Esc = Matriz3x3::Escala(sx, sy);
    Matriz3x3 Rot = Matriz3x3::Rotaciona(angulo);
    Matriz3x3 matrizComposta = Trans.multiplicarMatriz(Rot).multiplicarMatriz(Esc);
    QList<std::vector<float>> Transformados;
    for (const auto& ponto : Originais) {
        Transformados.append(matrizComposta.multiplicarVetor(ponto));
    }

    formaGeometrica* forma = listaDesenho.criarForma(Transformados, formasBase[i].getNome());

    int qtdLinhas = ui->tabela->rowCount();
    ui->tabela->insertRow(qtdLinhas);
    ui->tabela->setItem(qtdLinhas, 0, new QTableWidgetItem(forma->getNome()));
    ui->tabela->setItem(qtdLinhas, 1, new QTableWidgetItem(QString::number(contador)));
    contador++;
}

void MainWindow::removerFormaSelecionada() {
    QModelIndexList linhaTabela = ui->tabela->selectionModel()->selectedRows();
    std::sort(linhaTabela.begin(), linhaTabela.end(), [](const QModelIndex &a, const QModelIndex &b) {
        return a.row() > b.row(); //ordenar de baixo para cima não bagunça a lista
    });

    for (const QModelIndex& index : linhaTabela) {
        int linha = index.row();
        listaDesenho.removerFormaPorIndice(linha);
        ui->tabela->removeRow(linha);
    }
}

formaGeometrica MainWindow::getFormaSelecionada() const
{
    int i = this->getIndiceAtual();
    return formasBase[i];
}

int MainWindow::getIndiceAtual() const
{
    return ui->selectBox->currentIndex();
}


MainWindow::~MainWindow()
{
    delete ui;
}


