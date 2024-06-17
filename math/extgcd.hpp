#include "../../kyopro_library/template.hpp"

tuple<ll, ll, ll> extgcd(ll a, ll b) {
    if (b == 0) {
        return make_tuple(a, 1, 0);
    }
    ll q = a / b, r = a % b;
    auto [g, s, t] = extgcd(b, r);
    ll x = t;
    ll y = s - q * t;
    return make_tuple(g, x, y);
}

ll modinv(ll a, ll mod) {
    auto [g, x, y] = extgcd(a, mod);
    if (g != 1) {
        return -1;
    }
    return x % mod;
}