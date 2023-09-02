#include    <stdio.h>

int main(void)
{
    const char D[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char code[5];
    int j, number, base = 1000, sum = 0;

    printf("numberは？");
    scanf("%d", &number);

    if (number <= 0 || number >= 10000) {
        number = 0;
    }

    printf("連番 * 重み\n");
    for (int i = 0; i < 4; i++) {
        j = number / base;
        code[i] = D[j];
        sum += j * (4 - i);
        number %= base;
        base /= 10;
        printf("%4c * %2d = %d\n", code[i], 4 - i, j * (4 - i));
    }
    printf("重み付けの総和 = %d\n", sum);
    code[4] = D[sum % 10];

    printf("よって、商品コードは : ");
    for (int i = 0; i <= 4; i++) {
        printf("%c", code[i]);
    }
    
    return 0;
}