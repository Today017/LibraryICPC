#include "../../kyopro_library/template.hpp"

struct dynamic_modint {
    ll value;
    static ll mod;
    static void set_mod(ll x) {
        mod = x;
    }
    static ll get_mod() {
        return mod;
    }
    dynamic_modint(ll x = 0) {
        if (x >= 0) {
            value = x % mod;
        } else {
            value = mod - (-x) % mod;
        }
    }
    dynamic_modint operator-() const {
        return dynamic_modint(-value);
    }
    dynamic_modint operator+() const {
        return dynamic_modint(*this);
    }
    dynamic_modint &operator+=(const dynamic_modint &other) {
        value += other.value;
        if (value >= mod) {
            value -= mod;
        }
        return *this;
    }
    dynamic_modint &operator-=(const dynamic_modint &other) {
        value += mod - other.value;
        if (value >= mod) {
            value -= mod;
        }
        return *this;
    }
    dynamic_modint &operator*=(const dynamic_modint other) {
        value = value * other.value % mod;
        return *this;
    }
    dynamic_modint &operator/=(dynamic_modint other) {
        (*this) *= other.inv();
        return *this;
    }
    dynamic_modint operator+(const dynamic_modint &other) const {
        return dynamic_modint(*this) += other;
    }
    dynamic_modint operator-(const dynamic_modint &other) const {
        return dynamic_modint(*this) -= other;
    }
    dynamic_modint operator*(const dynamic_modint &other) const {
        return dynamic_modint(*this) *= other;
    }
    dynamic_modint operator/(const dynamic_modint &other) const {
        return dynamic_modint(*this) /= other;
    }
    dynamic_modint pow(ll x) const {
        dynamic_modint ret(1), mul(value);
        while (x) {
            if (x & 1) {
                ret *= mul;
            }
            mul *= mul;
            x >>= 1;
        }
        return ret;
    }
    dynamic_modint inv() const {
        return pow(mod - 2);
    }
    bool operator==(const dynamic_modint &other) const {
        return value == other.value;
    }
    bool operator!=(const dynamic_modint &other) const {
        return value != other.value;
    }
    friend ostream &operator<<(ostream &os, const dynamic_modint &x) {
        return os << x.value;
    }
    friend istream &operator>>(istream &is, dynamic_modint &x) {
        ll v;
        is >> v;
        x = dynamic_modint(v);
        return is;
    }
};
ll dynamic_modint::mod = 998244353;