#include <immintrin.h>
#define BMI2 __attribute__((__target__("bmi2")))
BMI2 long long minEnd(const uint n, const uint x) {
    return x | _pdep_u64(n - 1u, ~(uint64_t)x);
}