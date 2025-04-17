#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formageometrica.h"
#include "gerenciador.h"

class DrawArea;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getIndiceAtual() const;
    formaGeometrica getFormaSelecionada() const;
    Gerenciador listaDesenho;

private:
    Ui::MainWindow *ui;
    QList<formaGeometrica> formasBase;
    DrawArea* canvas;
    QStringList listaObjetos;
    int contador;
    int contadorLinha;
    void configuraUi();
    void configuraSelectBox();
    void configuraFormasBase();
    void configuraTabela();
    void configuraSlots();
    void adicionarFormaTabela();
    void removerFormaSelecionada();
};
#endif // MAINWINDOW_H
