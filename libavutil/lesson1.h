#ifndef LESSON1_H

#define LESSON1_H

#include <stdint.h>

void ff_add_values_c(uint8_t *src, const uint8_t *src2);
void ff_add_values_sse2(uint8_t *src, const uint8_t *src2);

#endif /* LESSON1_H*/