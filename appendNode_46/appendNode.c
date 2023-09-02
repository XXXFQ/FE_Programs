#include <stdio.h>
#include <stdbool.h>

int heap[] = { 0, 95, 74, 83, 65, 36, 21, -1, -1, -1 };
int n = 6;

void show_space(int spaceRange)
{
    for (int space = 1; space < spaceRange; space++) {
        putchar(' ');
    }
}

void appendNode(int num)
{
    int i, j, tmp;

    i = n + 1;
    heap[i] = num;
    j = i / 2;

    while (j >= 1 && heap[i] > heap[j]) {
        tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
        i = j;
        j = i / 2;
    }
    n++;
}

void show_heap()
{
    void show_space(int);
    int nodeIndex = 1, maxNodeIndex = 1;
    int spaceRange = 1, maxDepth = 0;

    if (n == 0) return;
    while (spaceRange < n) {
        maxDepth++;
        spaceRange = spaceRange * 2 + 1;
    }

    for (int depth = 0; depth <= maxDepth; depth++) {
        show_space(spaceRange);
        bool isLeftChild = true;
        
        do {
            // ノードの値を表示
            printf(isLeftChild ? "%-2d" : "%2d", heap[nodeIndex++]);
            if (nodeIndex > maxNodeIndex) { break; }
            show_space(spaceRange * 2 + 1);
            isLeftChild = !isLeftChild;
        } while (nodeIndex <= maxNodeIndex);
        putchar('\n');

        if (depth != maxDepth) {
            putchar('\n');
            maxNodeIndex = (maxNodeIndex * 2 + 1 < n) ? maxNodeIndex * 2 + 1 : n;
            spaceRange /= 2;
        }
    }
}

int main(void)
{
    int x;
    
    for (int i = 1; i <= 3; i++) {
        show_heap();
        printf("%d番目の数値は ? ", i);
        scanf("%d", &x);
        appendNode(x);
    }
    show_heap();

    return 0;
}