#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int popcnt(uint32_t a)
{
    int cnt = 0;
    while (a != 0) {
        a &= (a - 1);
        cnt++;
    }
    return cnt;
}

int *count_bits(int n, int *rsize)
{
    int *res = malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        res[i] = popcnt(i);
    }

    *rsize = n + 1;
    return res;
}

int main(void)
{
    int rsize;
    int *res = count_bits(2, &rsize);

    printf("[%d", res[0]);
    for (int i = 1; i < rsize; i++) {
        printf(",%d", res[i]);
    }
    printf("]\n");

    return 0;
}
