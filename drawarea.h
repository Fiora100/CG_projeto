#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include "formageometrica.h"
#include "gerenciador.h"

class MainWindow;

class DrawArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawArea(QWidget *parent = nullptr);

    void setMainWindow(MainWindow *mainWindowPtr);
    void paintEvent(QPaintEvent *) override;
    void genDrawing();

private:
    MainWindow *m_mainWindow;  // ponteiro tela principal
    Gerenciador *listaDesenho;  //ponteiro para lista do que desenhar

};

#endif // DRAWAREA_H
