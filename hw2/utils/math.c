#include <stdint.h>

int div(int dividend, int divisor, int *rem)
{
    int quotient = 0;
    while (dividend >= divisor) {
        quotient++;
        dividend -= divisor;
    }

    if (rem) {
        *rem = dividend;
    }
    return quotient;
}

uint64_t mul(uint32_t a, uint32_t b)
{
    uint64_t res = 0;
    while (b--) {
        res += a;
    }
    return res;
}
