#include <stdio.h>

// only print element with odd index (1,3, ...) in reverse order
void printOddOnlyReversed(int* tab, int size) {
    for (signed int i = size-1; i>=0; i-=2) { // signed <- unsigned int, >=0 <- <0
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int main()
{
    int testB[5] = { 0, 1, 2, 3, 4};
    printOddOnlyReversed(testB, 5);

    int testA[6] = { 0, 1, 2, 3, 4, 5};
    printOddOnlyReversed(testA, 6);

    return 0;
}
