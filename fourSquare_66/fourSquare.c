#include <stdio.h>
#include <string.h>
#include <math.h>

// ラグランジュの四平方定理
int main(void)
{
    int a[] = { 0, 0, 0, 0, 0 };
    int i = 1, sum = 0, max;

    printf("求めたい数値を入力して下さい : ");
    scanf("%d", a);

    // バックトラック法で探索
    while (a[0] != sum) {
        if (a[i] == 0) {
            max = sqrt(a[0] - sum);
            a[i] = (a[i - 1] > max) ? max : a[i - 1];
        } else {
            // 正しい結果が得られなかった場合、前の仮定を変更する
            sum -= pow(a[i], 2);
            a[i]--;
        }
        if (a[i] >= 1) {
            sum += pow(a[i], 2); // a[i]を正しいと仮定し、2乗して加算する。
            if (i < 4) {
                i++;
            }
        } else {
            i--;
        }   
    }

    // 結果表示
    printf("%d = ", a[0]);
    for (i = 1; i <= 4; i++) {
        printf(i != 4 ? "%d^2 + " : "%d^2", a[i]);
    }
    
    return 0;
}