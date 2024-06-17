#include "../../../kyopro_library/template.hpp"

vector<ll> dijkstra(const vector<vector<pair<int, ll>>> &G, int start = 0) {
    int n = G.size();
    vector<ll> dst(n, INFL);
    priority_queue<pair<ll, int>> pq;
    dst[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [dst_sum, now] = pq.top();
        pq.pop();
        dst_sum = -dst_sum;
        if (dst[now] < dst_sum) continue;
        for (auto [nxt, cost] : G[now]) {
            if (dst[nxt] > dst[now] + cost) {
                dst[nxt] = dst[now] + cost;
                pq.push({-dst[nxt], nxt});
            }
        }
    }
    return dst;
}