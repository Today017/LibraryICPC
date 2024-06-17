#include "../../kyopro_library/mod/modint.hpp"

template <typename T>
struct combination {
    vector<T> fact, factinv;
    combination(int n) {
        fact = vector<T>(n + 1);
        factinv = vector<T>(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        for (int i = 0; i <= n; i++) {
            factinv[i] = fact[i].inv();
        }
    }
    T nCr(ll n, ll r) {
        if (n < 0 || r < 0 || n - r < 0) {
            return 0;
        }
       return fact[n] * factinv[r] * factinv[n - r];
    }
    T nPr(ll n, ll r) {
        if (n < 0 || r < 0 || n - r < 0) {
            return 0;
        }
        return fact[n] * factinv[n - r];
    }
    T operator()(ll n, ll r) {
        return nCr(n, r);
    }
};
