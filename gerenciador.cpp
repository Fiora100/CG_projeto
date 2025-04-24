#include "gerenciador.h"

Gerenciador::~Gerenciador() {
    limparFormas();
}

formaGeometrica* Gerenciador::criarForma(const QList<std::vector<float>>& pontos, const QString& nome) {
    formaGeometrica* novaForma = new formaGeometrica(pontos, nome);
    formas.append(novaForma);
    return novaForma;
}

void Gerenciador::removerFormaPorIndice(int index) {
    if (index >= 0 && index < formas.size()) {
        delete formas[index];
        formas.removeAt(index);
    }
}

void Gerenciador::limparFormas() {
    for (formaGeometrica* forma : formas) {
        delete forma;
    }
    formas.clear();
}

const QList<formaGeometrica*>& Gerenciador::getFormas() const {
    return formas;
}
