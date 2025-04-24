#include "drawarea.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QString>

DrawArea::DrawArea(QWidget *parent)
    : QWidget(parent), m_mainWindow(nullptr)
{
}

static QPointF vectorToQPointF(const std::vector<float>& vec) {
    if (vec.size() >= 2) {
        return QPointF(vec[0], vec[1]); // Ignore the 3rd coordinate (usually 1 in homogeneous coords)
    }
    return QPointF(); // Fallback in case of bad data
}

void DrawArea::paintEvent(QPaintEvent *)
{
    if (m_mainWindow != nullptr) {
        QPainter painter(this);
        QPen caneta(Qt::black, 3);
        painter.setPen(caneta);
        painter.setRenderHint(QPainter::Antialiasing);

        const QList<formaGeometrica*>& formas = m_mainWindow->listaDesenho.getFormas();

        for (formaGeometrica* atual : formas) {
            QList<std::vector<float>> formaAtual = atual->getPontos();

            if (formaAtual.size() == 1 && formaAtual[0].size() >= 2) {
                painter.drawPoint(vectorToQPointF(formaAtual[0]));
            } else {
                for (int j = 0; j < formaAtual.size(); ++j) {
                    QPointF ponto1 = vectorToQPointF(formaAtual[j]);
                    QPointF ponto2 = vectorToQPointF(formaAtual[(j + 1) % formaAtual.size()]);
                    painter.drawLine(ponto1, ponto2);
                }
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
