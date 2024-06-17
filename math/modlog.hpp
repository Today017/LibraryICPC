#include "../../kyopro_library/template.hpp"

ll modlog(ll x, ll y, ll mod) {
    ll m = ceil(sqrt(mod)) + 1;
    ll now_y = y;
    map<ll, ll> mp;
    for (int i = 0; i < m; i++) {
        mp[now_y] = i;
        now_y = now_y * x % mod;
    }
    ll x_pow = 1;
    for (int i = 0; i < m; i++) {
        x_pow *= x;
        x_pow %= mod;
    }
    ll now_x = x_pow;
    for (ll i = 1; i <= m; i++) {
        if (mp.find(now_x) != mp.end()) {
            return i * m - mp[now_x];
        }
        now_x = now_x * x_pow % mod;
    }
    return -1;
}
