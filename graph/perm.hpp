

struct permutation_decomposition {
    int n;
    vector<int> p, invp;
    vector<vector<int>> cycles;
    permutation_decomposition(const vector<int>& p) {
        n = p.size();
        this->p = p;
        invp = vector<int>(n);
        for (int i = 0; i < n; i++) {
            invp[p[i]] = i;
        }
        vector<bool> used(n, false);
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }
            vector<int> cycle;
            int now = i;
            while (!used[now]) {
                cycle.push_back(now);
                used[now] = true;
                now = p[now];
            }
            cycles.push_back(cycle);
        }
    }
    vector<vector<int>> get_decomposition() {
        return cycles;
    }
};
