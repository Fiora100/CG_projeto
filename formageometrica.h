#ifndef FORMAGEOMETRICA_H
#define FORMAGEOMETRICA_H
#include <QPoint>
#include <QList>
#include <QString>

class formaGeometrica
{
public:
    formaGeometrica(const QList<QPoint> &pontos, const QString &nome);

    QString getNome() const;
    QList<QPoint> getPontos() const;
private:
    QString f_nome;
    QList<QPoint> f_pontos;
};

#endif // FORMAGEOMETRICA_H
