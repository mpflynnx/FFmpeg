#include "example.h"

void ff_add_bytes_c(uint8_t *dst, uint8_t *src, int len) {
    for (int i = 0; i < len; i++)
        dst[i] += src[i];
}

