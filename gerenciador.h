#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include "formageometrica.h"
#include <QList>
#include <QString>

class Gerenciador {
public:
    ~Gerenciador();

    formaGeometrica* criarForma(const QList<QPoint>& pontos, const QString& nome);
    void removerFormaPorIndice(int index);
    void limparFormas();
    const QList<formaGeometrica*>& getFormas() const;

private:
    QList<formaGeometrica*> formas;
};

#endif // GERENCIADOR_H
