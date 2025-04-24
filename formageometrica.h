#ifndef FORMAGEOMETRICA_H
#define FORMAGEOMETRICA_H
#include <QPoint>
#include <QList>
#include <QString>
#include <vector>

class formaGeometrica
{
public:
    formaGeometrica(const QList<std::vector<float>> &pontos, const QString &nome)
        : f_nome(nome), f_pontos(pontos)
    {}
    QString f_nome;
    QList<std::vector<float>> f_pontos;

    QString getNome() const {
    return f_nome;
    }
    QList<std::vector<float>> getPontos() const {
    return f_pontos;
    }

};
#endif // FORMAGEOMETRICA_H
