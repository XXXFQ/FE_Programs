#include <stdio.h>

/* isoscelesTriangle */
int main(void)
{
    int n;
    
    printf("等辺の長さは? ");
    scanf("%d", &n);

    for (int line = 1; line <= n; line++) {
        for (int cnt = 1; cnt <= line; cnt++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}