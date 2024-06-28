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



vector<ll> euler_phi_table(ll n) {
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
