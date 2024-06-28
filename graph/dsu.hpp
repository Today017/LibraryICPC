struct disjoint_set_union {
    disjoint_set_union() = default;
    disjoint_set_union(int n) {
        par = vector<int>(n);
        sz = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
        forest_count = n;
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        par[x] = find(par[x]);
        return par[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        par[y] = x;
        sz[x] += sz[y];
        forest_count--;
    }
    int size(int x) {
        return sz[find(x)];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    vector<vector<int>> groups() {
        int n = par.size();
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            res[find(i)].push_back(i);
        }
        res.erase(remove_if(res.begin(), res.end(), [&](const vector<int>& v) { return v.empty(); }), res.end());
        return res;
    }

private:
    vector<int> par, sz;
    int forest_count;
};
