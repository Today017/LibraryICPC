#include "../../kyopro_library/template.hpp"

struct factors {
    factors(int n) {
        mx = n;
        min_factor = vector<int>(mx + 1);
        is_prime = vector<bool>(mx + 1, true);
        is_prime[0] = is_prime[1] = false;
        divisors = vector<vector<int>>(mx + 1);
        prime_factors = vector<vector<pair<int, int>>>(mx + 1);
        for (int i = 2; i <= mx; i++) {
            if (is_prime[i]) {
                min_factor[i] = i;
                for (int j = 2 * i; j <= mx; j += i) {
                    is_prime[j] = false;
                    if (min_factor[j] == 0) {
                        min_factor[j] = i;
                    }
                }
            }
        }
    }
    vector<pair<int, int>> get_prime_factors(int n) {
        if (prime_factors[n].size() == 0) {
            int x = n;
            while (x > 1) {
                int p = min_factor[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                prime_factors[n].push_back({p, cnt});
            }
        }
        return prime_factors[n];
    }
    vector<int> get_divisors(int n) {
        if (divisors[n].size() == 0) {
            vector<pair<int, int>> pf = get_prime_factors(n);
            int sz = pf.size();
            auto dfs = [&](auto&& dfs, int i, int x) -> void {
                if (i == sz) {
                    divisors[n].push_back(x);
                    return;
                }
                auto [p, cnt] = pf[i];
                for (int j = 0; j <= cnt; j++) {
                    dfs(dfs, i + 1, x);
                    x *= p;
                }
            };
            dfs(dfs, 0, 1);
            sort(divisors[n].begin(), divisors[n].end());
        }
        return divisors[n];
    }

private:
    int mx;
    vector<int> min_factor;
    vector<bool> is_prime;
    vector<vector<int>> divisors;
    vector<vector<pair<int, int>>> prime_factors;
};
