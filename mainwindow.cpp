#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QString>
#include <QDebug>

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
    QList<QList<QPoint>> pontosFormas = {
        { QPoint(this->width()/2, this->height()/2) },                                         // Ponto
        { QPoint(60, 30), QPoint(90, 30) },                         // Linha
        { QPoint(30, 90), QPoint(110, 90), QPoint(50, 30) },         // Triângulo
        { QPoint(10, 90), QPoint(90, 90), QPoint(90, 10), QPoint(10, 10) },                 // Quadrado
        { QPoint(60, 20), QPoint(90, 45), QPoint(80, 85), QPoint(40, 85), QPoint(30, 45) }  // Pentagono
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
    formaGeometrica* forma = listaDesenho.criarForma(formasBase[i].getPontos(), formasBase[i].getNome());
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

