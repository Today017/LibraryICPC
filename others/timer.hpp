#pragma once
#include "../../kyopro_library/template.hpp"

struct timer {
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point time_limit;
    timer(ll time_limit_msec = 5000) : start(chrono::high_resolution_clock::now()) {
        time_limit = start + chrono::microseconds((ll)(time_limit_msec * 1e3));
    }
    inline ll get() {
        auto now = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(now - start).count();
    }
    inline bool check() {
        auto now = chrono::high_resolution_clock::now();
        return now < time_limit;
    }
};
