#include "formageometrica.h"

formaGeometrica::formaGeometrica(const QList<QPoint> &pontos, const QString &nome)
    : f_nome(nome), f_pontos(pontos)
{
}

QString formaGeometrica::getNome() const {
    return f_nome;
}

QList<QPoint> formaGeometrica::getPontos() const {
    return f_pontos;
}
