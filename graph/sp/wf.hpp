#include "../../../kyopro_library/template.hpp"

void warshall_floyd(vector<vector<ll>> &G) {
    int n = G.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (G[i][k] == INFL || G[k][j] == INFL) continue;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

