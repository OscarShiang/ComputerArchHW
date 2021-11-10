#include <stdbool.h>
#include <stdint.h>

#include "math.h"

static volatile uint8_t *tx = (uint8_t *) 0x40002000;

static void put_char(char c)
{
    *tx = c;
}

void print_str(const char *str)
{
    while (*str) {
        put_char(*str++);
    }
}

static const uint32_t pow10[] = {
    1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

void print_int(int a)
{
    bool printed = false;
    for (int i = 0; i < 10; i++) {
        if (a >= pow10[i]) {
            int rem;
            printed = true;
            put_char(div(a, pow10[i], &rem) + '0');
            a = rem;
        } else if (printed) {
            put_char('0');
        }
    }

    if (!printed)
        put_char('0');
}
