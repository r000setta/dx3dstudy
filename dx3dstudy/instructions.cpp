// InstructionSet.cpp
// Compile by using: cl /EHsc /W4 InstructionSet.cpp
// processor: x86, x64
// Uses the __cpuid intrinsic to get information about
// CPU extended instruction set support.

#include <iostream>

#include <immintrin.h>

void test() {
    __m128 a = _mm_set_ps(1, 2, 3, 4);
    __m128 b = _mm_set_ps(5, 6, 7, 8);
    __m128 v = _mm_shuffle_ps(a, b, _MM_SHUFFLE(1, 0, 3, 2));
}