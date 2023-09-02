#include <stdio.h>

void insertNum(int a[], const int n, int x)
{
    int i = 0, k;
    int j = n - 1;

    while (i <= j) {
        k = (i + j) / 2;
        if (x >= a[k]) {
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    for (j = n; j >= i + 1; j--) {
        a[j] = a[j - 1];
    }
    a[i] = x;
}

int main(void)
{
    int a[9], x;
    const int size = sizeof(a) / sizeof(int);

    printf("数値を入力してください。\n");
    for (int i = 0; i < size; i++) {
        printf("%d番目は? : ", i + 1);
        scanf("%d", &x);
        insertNum(a, i, x);
    }

    printf("配列aの中身 = ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}