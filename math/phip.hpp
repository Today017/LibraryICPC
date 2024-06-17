#include "../../kyopro_library/template.hpp"

vector<ll> euler_phi(ll n) {
    vector<ll> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    for (ll i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (ll j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    return phi;
}
