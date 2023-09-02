#include <stdio.h>

void simple_perceptron(float w[], float bias, int y[])
{
    // ノードの値
    int x[4][2] = {
        { 0, 0 },
        { 0, 1 },
        { 1, 0 },
        { 1, 1 }
    };
    float ytemp;

    for (int out = 0; out < 4; out++) {
        ytemp = bias;
        for (int in = 0; in < 2; in++) {
            ytemp += x[out][in] * w[in];
        }
        y[out] = (ytemp > 0) ? 1 : 0;
    }
}

int main(void)
{
    float bias = -0.7;
    float w[] = { 0.5, 0.5 }; // 重み
    int y[4]; // 演算結果

    simple_perceptron(w, bias, y);

    for (int i = 2; i >= 0; i-= 2) {
        for (int j = 0; j <= 1; j++) {
            printf("%d ", y[i + j]);
        }
        printf("\n");
    }
    return 0;
}