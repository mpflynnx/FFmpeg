#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdint.h>

void ff_add_bytes_c(uint8_t *dst, uint8_t *src, int len);
void ff_add_bytes_sse2(uint8_t *dst, uint8_t *src, int len);

#endif /* EXAMPLE_H */