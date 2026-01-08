#include <string.h>
#include "checkasm.h"
#include "libavutil/lesson1.h"
#include "libavutil/mem_internal.h"

// 1. Define the size of the test buffer. 
// We use a multiple of 16/32 to satisfy SIMD alignment.
#define BUF_SIZE 1024

void checkasm_check_lesson1(void)
{
    // 2. Setup buffers. We use LOCAL_ALIGNED to ensure the memory is 
    // properly aligned for SIMD instructions (SSE/AVX).
    LOCAL_ALIGNED_32(uint8_t, src,     [BUF_SIZE]);
    LOCAL_ALIGNED_32(uint8_t, dst_ref, [BUF_SIZE]);
    LOCAL_ALIGNED_32(uint8_t, dst_new, [BUF_SIZE]);

    // We define a pointer for the function we are testing
    void (*add_values_ptr)(uint8_t *, uint8_t *) = ff_add_values_c;

    // 3. Declare the function signature. 
    // Format: (return_type, arg1, arg2, arg3...)
    // void ff_add_values_c(uint8_t *src, const uint8_t *src2)
    declare_func(void, uint8_t *src, const uint8_t *src2);


	// 4. Fill the source and destination buffers with random data.
    // Instead of rng_fill, we use the rnd() macro in a loop:
    for (int i = 0; i < BUF_SIZE; i++) {
        src[i]     = rnd() & 0xFF; // Mask to 8-bit
        dst_ref[i] = rnd() & 0xFF;
    }
    memcpy(dst_new, dst_ref, BUF_SIZE);

    // 5. Test the function
    // "add_bytes" is the name displayed in the report.
    if (check_func(ff_add_values_c, "add_values")) {
        
        // Call the C reference version
        call_ref(dst_ref, src);
        
        // Call your new Assembly version
        call_new(dst_new, src);

        // 6. Verification: Check if the results match exactly.
        if (memcmp(dst_ref, dst_new, BUF_SIZE)) {
            fail();
        }

        // 7. Benchmarking: Measure the CPU cycles.
        // This only runs if you pass the --bench flag to checkasm.
        bench_new(dst_new, src);
    }

    // 2. Now, we check the SIMD version
    // This is where the magic happens!
    add_values_ptr = ff_add_values_sse2; // Make sure this is declared/linked!

    if (check_func(add_values_ptr, "add_values_sse2")) {
        declare_func(void, uint8_t *src, const uint8_t *src2);
        
        call_ref(dst_ref, src); // Runs C version
        call_new(dst_new, src); // Runs SSE2 version

        if (memcmp(dst_ref, dst_new, BUF_SIZE))
            fail();

        bench_new(dst_new, src);
    }

    // 8. Final report
    report("add_values");
}
