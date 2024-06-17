#include "../../kyopro_library/template.hpp"    

struct rolling_hash {
    rolling_hash(const string &s, vector<ll> base = {}) {
        int n = s.size();
        mt19937 rng(time(0));
        this->base = vector<ll>(5);
        power = vector<vector<ll>>(5);
        hash_table = vector<vector<ll>>(5);
        inv = vector<vector<ll>>(5);
        if (base.size() != 5) {
            base = get_base();
        } else {
            this->base = base;
        }
        base = this->base;
        for (int i = 0; i < 5; i++) {
            power[i] = vector<ll>(n + 1);
            hash_table[i] = vector<ll>(n + 1);
            inv[i] = vector<ll>(n + 1);
            power[i][0] = 1;
            inv[i][n] = pow_mod(pow_mod(base[i], n, mod[i]), mod[i] - 2, mod[i]);
        }
        for (int i = 0; i < n; i++) {
            int num = s[i] - 'A';
            for (int j = 0; j < 5; j++) {
                power[j][i + 1] = mul_mod(power[j][i], base[j], mod[j]);
                hash_table[j][i + 1] = add_mod(hash_table[j][i], mul_mod(power[j][i], num, mod[j]), mod[j]);
                inv[j][n - i - 1] = mul_mod(inv[j][n - i], base[j], mod[j]);
            }
        }
    }
    static const vector<ll> mod;
    static vector<ll> get_base() {
        vector<ll> base(5);
        mt19937 rng(time(0));
        for (int i = 0; i < 5; i++) {
            base[i] = (rng() % mod[i] + 3000) % mod[i];
        }
        return base;
    }
    using hash = array<ll, 5>;
    hash get(int l, int r) {
        hash ret;
        for (int i = 0; i < 5; i++) {
            ret[i] = mul_mod(add_mod(hash_table[i][r], -hash_table[i][l], mod[i]), inv[i][l], mod[i]);
        }
        return ret;
    }
    hash connect(hash h1, hash h2, int len1) {
        hash ret;
        for (int i = 0; i < 5; i++) {
            ret[i] = add_mod(h1[i], mul_mod(h2[i], power[i][len1], mod[i]), mod[i]);
        }
        return ret;
    }

private:
    vector<ll> base;
    vector<vector<ll>> power, hash_table, inv;
    inline ll mul_mod(ll a, ll b, ll mod) {
        return a * b % mod;
    }
    inline ll add_mod(ll a, ll b, ll mod) {
        ll ret = a + b;
        if (ret >= mod) {
            ret -= mod;
        }
        if (ret < 0) {
            ret += mod;
        }
        return ret;
    }
    ll pow_mod(ll a, ll x, ll mod) {
        ll ret = 1;
        while (x) {
            if (x & 1) {
                ret = mul_mod(ret, a, mod);
            }
            a = mul_mod(a, a, mod);
            x >>= 1;
        }
        return ret;
    }
};
const vector<ll> rolling_hash::mod = {1000000009, 1000000007, 1000000021, 1000000033, 1000000087};