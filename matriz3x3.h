#ifndef MATRIZ3X3_H
#define MATRIZ3X3_H

#include <vector>
#include <cmath>
class Matriz3x3 {
public:
    float matriz[3][3];

    // identidade
    Matriz3x3() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                matriz[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    static Matriz3x3 Translada(float dx, float dy) {
        Matriz3x3 m;
        m.matriz[0][2] = dx;
        m.matriz[1][2] = dy;
        return m;
    }

    static Matriz3x3 Escala(float sx, float sy) {
        Matriz3x3 m;
        m.matriz[0][0] = sx;
        m.matriz[1][1] = sy;
        return m;
    }

    static Matriz3x3 Rotaciona(float graus) {
        Matriz3x3 m;
        float rad = graus * M_PI / 180.0f;  // radianos
        float cosA = cos(rad);
        float sinA = sin(rad);

        m.matriz[0][0] = cosA;
        m.matriz[0][1] = -sinA;
        m.matriz[1][0] = sinA;
        m.matriz[1][1] = cosA;
        return m;
    }

    Matriz3x3 multiplicarMatriz(const Matriz3x3& outra) const {
        Matriz3x3 resultado;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                resultado.matriz[i][j] = 0.0f;
                for (int k = 0; k < 3; ++k)
                    resultado.matriz[i][j] += matriz[i][k] * outra.matriz[k][j];
            }
        return resultado;
    }

    std::vector<float> multiplicarVetor(const std::vector<float>& vetor) const {
        std::vector<float> resultado(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                resultado[i] += matriz[i][j] * vetor[j];
        return resultado;
    }
};

#endif // MATRIZ3X3_H
