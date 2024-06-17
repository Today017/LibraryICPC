#include "../../kyopro_library/template.hpp"

ll euler_phi(ll n) {
    ll ret = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ret -= ret / n;
    }
    return ret;
}

ll euler_phi2(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    ll m = divs.size();
    vector<ll> dp(m);
    for (int i = m - 1; i >= 0; i--) {
        dp[i] = n / divs[i];
        for (int j = i + 1; j < m; j++) {
            if (divs[j] % divs[i] == 0) {
                dp[i] -= dp[j];
            }
        }
    }
    return dp[0];
}
