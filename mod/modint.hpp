#pragma once
#include "../../kyopro_library/template.hpp"

template <ll MOD>
struct modint {
    ll value;
    modint(ll x = 0) {
        if (x >= 0) {
            value = x % MOD;
        } else {
            value = MOD - (-x) % MOD;
        }
    }
    modint operator-() const {
        return modint(-value);
    }
    modint operator+() const {
        return modint(*this);
    }
    modint &operator+=(const modint &other) {
        value += other.value;
        if (value >= MOD) {
            value -= MOD;
        }
        return *this;
    }
    modint &operator-=(const modint &other) {
        value += MOD - other.value;
        if (value >= MOD) {
            value -= MOD;
        }
        return *this;
    }
    modint &operator*=(const modint other) {
        value = value * other.value % MOD;
        return *this;
    }
    modint &operator/=(modint other) {
        (*this) *= other.inv();
        return *this;
    }
    modint operator+(const modint &other) const {
        return modint(*this) += other;
    }
    modint operator-(const modint &other) const {
        return modint(*this) -= other;
    }
    modint operator*(const modint &other) const {
        return modint(*this) *= other;
    }
    modint operator/(const modint &other) const {
        return modint(*this) /= other;
    }
    modint pow(ll x) const {
        modint ret(1), mul(value);
        while (x) {
            if (x & 1) {
                ret *= mul;
            }
            mul *= mul;
            x >>= 1;
        }
        return ret;
    }
    modint inv() const {
        return pow(MOD - 2);
    }
    bool operator==(const modint &other) const {
        return value == other.value;
    }
    bool operator!=(const modint &other) const {
        return value != other.value;
    }
    friend ostream &operator<<(ostream &os, const modint &x) {
        return os << x.value;
    }
    friend istream &operator>>(istream &is, modint &x) {
        ll v;
        is >> v;
        x = modint<MOD>(v);
        return is;
    }
};
using mod998 = modint<998244353>;
using mod107 = modint<1000000007>;
