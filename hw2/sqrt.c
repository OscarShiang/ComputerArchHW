#include <stdint.h>

#include "math.h"
#include "print.h"

uint32_t mysqrt(uint32_t x)
{
    uint64_t lo = 0, hi = x + 1u;
    while (lo < hi) {
        uint64_t mi = (hi - lo) / 2 + lo;
        if (mul(mi, mi) <= x)
            lo = mi + 1;
        else
            hi = mi;
    }
    return lo - 1;
}

void _start()
{
    int a = 4096;

    print_str("sqrt(");
    print_int(a);
    print_str(") = ");
    print_int(mysqrt(a));
    print_str("\n");
}
