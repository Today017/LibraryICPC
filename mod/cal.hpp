#include "../../kyopro_library/template.hpp"

ll pow_mod(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = ret * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

ll inv_mod(ll x, ll mod) {
    return pow_mod(x, mod - 2, mod);
}
