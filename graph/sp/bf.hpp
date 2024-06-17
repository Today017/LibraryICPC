#include "../../../kyopro_library/template.hpp"

pair<bool, vector<ll>> bellman_ford(const vector<vector<pair<int, ll>>> &G, int start) {
    int n = G.size();
    vector<ll> dst(n, INFL);
    dst[start] = 0;
    int i = 0;
    for (; i < n; i++) {
        bool update = false;
        for (int j = 0; j < n; j++) {
            for (auto [nxt, cost] : G[j]) {
                if (dst[j] != INFL && dst[j] + cost < dst[nxt]) {
                    dst[nxt] = dst[j] + cost;
                    update = true;
                }
            }
        }
        if (!update) {
            break;
        }
    }
    return {i == n, dst};
}