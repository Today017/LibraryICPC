struct MF {
    struct Edge {
        int to, rev;
        ll cap;
    };
    vector<vector<Edge>> g;
    vector<bool> seen;
    MF(int n) : g(n), seen(n, false) {}
    void add(int u, int v, ll cap) {
        g[u].push_back({v, (int)g[v].size(), cap});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    }
    ll dfs(int now, int t, ll f) {
        if (now == t) return f;
        seen[now] = true;
        for (auto &e : g[now]) {
            if (seen[e.to] || e.cap == 0) continue;
            ll d = dfs(e.to, t, min(f, e.cap));
            if (d == 0) continue;
            e.cap -= d;
            g[e.to][e.rev].cap += d;
            return d;
        }
        return 0;
    }
    ll flow(int s, int t) {
        ll res = 0;
        while (true) {
            fill(seen.begin(), seen.end(), false);
            ll f = dfs(s, t, 1ll << 60);
            if (f == 0) return res;
            res += f;
        }
    }
};