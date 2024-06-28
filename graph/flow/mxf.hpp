template <typename Cap>
struct max_flow {
    max_flow() = default;
    max_flow(int n) {
        this->n = n;
        G = vector<vector<tuple<int, int, Cap>>>(n);
    }
    void add_edge(int u, int v, Cap c) {
        G[u].push_back(make_tuple(v, G[v].size(), c));
        G[v].push_back(make_tuple(u, (int)G[u].size() - 1, 0));
    }
    Cap get(int start, int goal) {
        Cap ret = 0;
        while (true) {
            vector<int> dst = calculate_distance(start);
            if (dst[goal] < 0) {
                return ret;
            }
            vector<int> removed(n, 0);
            while (true) {
                Cap add = flowing(start, goal, numeric_limits<Cap>::max(), removed, dst);
                if (add == 0) {
                    break;
                }
                ret += add;
            }
        }
        return ret;
    }

private:
    int n;
    vector<vector<tuple<int, int, Cap>>> G;
    vector<int> calculate_distance(int start) {
        vector<int> dst(n, -1);
        dst[start] = 0;
        queue<int> que;
        que.push(start);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (auto [nxt, _, cap] : G[now]) {
                if (cap > 0 && dst[nxt] == -1) {
                    dst[nxt] = dst[now] + 1;
                    que.push(nxt);
                }
            }
        }
        return dst;
    }
    Cap flowing(int now, int goal, Cap limit, vector<int> &removed, vector<int> &dst) {
        if (now == goal) {
            return limit;
        }
        while (removed[now] < (int)G[now].size()) {
            auto [nxt, rev, cap] = G[now][removed[now]];
            if (cap > 0 && dst[now] < dst[nxt]) {
                Cap flow = flowing(nxt, goal, min(limit, cap), removed, dst);
                if (flow > 0) {
                    get<2>(G[now][removed[now]]) -= flow;
                    get<2>(G[nxt][rev]) += flow;
                    return flow;
                }
            }
            removed[now]++;
        }
        return 0;
    }
};
