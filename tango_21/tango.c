#include <stdio.h>

int main(void)
{
    char* tango[5] = { "Cat", "Dog", "Horse", "0x", "Wolf" };
    char* work;
    int n = 5;

    for (int i = 0; i < n; i++) {
        printf("%s ", tango[i]);
    }
    printf("\n");

    if (n > 1) {
        work = tango[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            tango[i + 1] = tango[i];
        }
        tango[0] = work;
    }

    for (int i = 0; i < n; i++) {
        printf("%s ", tango[i]);
    }
    printf("\n");
}