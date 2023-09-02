#include <stdio.h>
#include <string.h>

int main(void)
{
    char target[41], keyword[11];
    int i, j, m, n, cnt;
    printf("target? "),scanf("%40s", target);
    printf("keyword? "),scanf("%10s", keyword);

    n = strlen(target);
    m = strlen(keyword);
    i = cnt = 0;

    while (i + m <= n) {
        j = 0;
        while (j < m && target[i + j] == keyword[j]) {
            j++;
        }
        if (j == m) {
            cnt++;
        }
        i++;
    }
    printf("一致した部分文字列は%d個です。", cnt);
    return 0;
}