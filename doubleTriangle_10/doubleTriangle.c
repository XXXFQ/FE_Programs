#include <stdio.h>

/* doubleTriangle */
int main(void)
{
    int n;
    
    printf("等辺の長さは? ");
    scanf("%d", &n);

    for (int line = 1; line <= n; line++) {
        for (int space = 1; space <= n - line; space++) {
            putchar(' ');
        }
        for (int star = 1; star <= line * 2 - 1; star++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}