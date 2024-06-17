#include "../../kyopro_library/template.hpp"

struct bezout_identity {
    ll a, b, c, g;
    ll X, Y;
    bezout_identity(ll a, ll b, ll c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
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
    bool build() {
        auto [g, X, Y] = extgcd(abs(a), abs(b));
        if (c % g != 0) {
            return false;
        }
        this->g = g;
        this->X = X;
        this->Y = Y;
        if (a < 0) {
            this->X = -this->X;
        }
        if (b < 0) {
            this->Y = -this->Y;
        }
        this->X *= c / g;
        this->Y *= c / g;
        return true;
    }
    pair<ll, ll> general_solution(ll t = 0) {
        ll x = b / g * t + X;
        ll y = -a / g * t + Y;
        return make_pair(x, y);
    }
};
