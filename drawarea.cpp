#include "drawarea.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QString>

DrawArea::DrawArea(QWidget *parent)
    : QWidget(parent), m_mainWindow(nullptr)
{
}

void DrawArea::paintEvent(QPaintEvent *)
{
if (m_mainWindow != nullptr)
    {
        QPainter painter(this);
        QPen caneta(Qt::black,3);
        painter.setPen(caneta);
        painter.setRenderHint(QPainter::Antialiasing);
        const QList<formaGeometrica*>& formas = m_mainWindow->listaDesenho.getFormas();
        for(formaGeometrica* atual : formas){
            QList<QPoint> formaAtual = atual->getPontos();
            if (formaAtual.size() == 1)                                 // verifica se a forma é um ponto
                painter.drawPoint(formaAtual[0]);
            else for (int j = 0; j < formaAtual.size(); ++j) {          //formas com mais de um vertice
                    QPoint ponto1 = formaAtual[j];
                    QPoint ponto2 = formaAtual[(j + 1) % formaAtual.size()];// ultimo liga primeiro. (logica de resto)
                    painter.drawLine(ponto1, ponto2);
                }
        }
    }
}

void DrawArea::setMainWindow(MainWindow *mainWindowPtr)
{
    m_mainWindow = mainWindowPtr;  // ponteiro para mainwindow
    listaDesenho = &m_mainWindow->listaDesenho;
}


void DrawArea::genDrawing()
{
    this->update();  // atualiza o canvas
}
