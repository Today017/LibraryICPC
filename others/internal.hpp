#pragma once
#include "../../kyopro_library/template.hpp"

namespace internal {
    template <typename T>
    T min(T a, T b) {
        return min(a, b);
    }
    template <typename T>
    T max(T a, T b) {
        return max(a, b);
    }
    template <typename T, typename U>
    T add(T a, U b) {
        return a + b;
    }
    int lg(int n) {
        return 31 - __builtin_clz(n);
    }
    int lg(ll n) {
        return 63 - __builtin_clzll(n);
    }
    int popcount(ll n) {
        return __builtin_popcountll(n);
    }
}  // namespace internal
