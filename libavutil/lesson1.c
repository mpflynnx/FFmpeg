#include "lesson1.h"

void ff_add_values_c(uint8_t *src, const uint8_t *src2){
    // https://gemini.google.com/app/8e3e68f76c1341c7
    //  size of the pointer *(*i.e in C it represents *sizeof(*src) == 8 on 64-bit systems
    
    for (int i = 0; i < 8; i++) {
        src[i] += src2[i];
    }
}