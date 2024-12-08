template <typename T, T (*op)(T, T), T (*e)()>
class RangeTree {
private:
    static const ll INFL = 1LL << 60;
    int n, sz;
    vector<segtree<T, op, e>> seg;
    vector<vector<pair<ll, ll>>> yx;
    vector<pair<ll, ll>> sorted;
    void update_(int id, ll x, ll y, T val) {
        id += n - 1;
        int yid = lb(yx[id], pair<ll, ll>(y, x));
        seg[id].set(yid, val);
        while (id > 0) {
            id = (id - 1) / 2;
            int yid = lb(yx[id], pair<ll, ll>(y, x));
            seg[id].set(yid, val);
        }
    }
    template <typename U>
    inline int lb(const vector<U>& v, const U& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
    T query(int lxid, int rxid, ll ly, ll ry, int k, int l, int r) {
        if (r <= lxid || rxid <= l) return e();
        if (lxid <= l && r <= rxid) {
            int lyid = lb(yx[k], pair<ll, ll>(ly, -INFL));
            int ryid = lb(yx[k], pair<ll, ll>(ry, -INFL));
            return (lyid >= ryid) ? e() : seg[k].prod(lyid, ryid);
        } else {
            return op(query(lxid, rxid, ly, ry, 2 * k + 1, l, (l + r) / 2),
                      query(lxid, rxid, ly, ry, 2 * k + 2, (l + r) / 2, r));
        }
    }

public:
    // 座標, 点の値
    RangeTree(vector<pair<ll, ll>>& cand, vector<T>& val) : n(1), sz(cand.size()), sorted(sz) {
        while (n < sz) n *= 2;
        for (int i = 0; i < sz; i++) sorted[i] = {cand[i].first, i};
        sort(sorted.begin(), sorted.end(), [&](pair<ll, ll>& a, pair<ll, ll>& b) {
            return (a.first == b.first) ? (cand[a.second].second < cand[b.second].second) : (a.first < b.first);
        });
        yx.resize(2 * n - 1), seg.resize(2 * n - 1);
        for (int i = 0; i < sz; i++) {
            yx[i + n - 1] = {{sorted[i].second, sorted[i].first}};
            vector<T> arg = {val[sorted[i].second]};
            seg[i + n - 1] = segtree<T, op, e>(arg);
            sorted[i].second = cand[sorted[i].second].second;
        }
        for (int i = n - 2; i >= 0; i--) {
            yx[i].resize(yx[2 * i + 1].size() + yx[2 * i + 2].size());
            if (yx[i].empty()) continue;
            merge(yx[2 * i + 1].begin(), yx[2 * i + 1].end(), yx[2 * i + 2].begin(), yx[2 * i + 2].end(), yx[i].begin(), [&](pair<ll, ll>& a, pair<ll, ll>& b) {
                return (cand[a.first].second == cand[b.first].second) ? (a.second < b.second)
                                                                      : (cand[a.first].second < cand[b.first].second);
            });
            vector<T> arg((int)yx[i].size());
            for (int j = 0; j < yx[i].size(); j++) arg[j] = val[yx[i][j].first];
            seg[i] = segtree<T, op, e>(arg);
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            for (auto& [a, b] : yx[i]) a = cand[a].second;
        }
    }
    void update(ll x, ll y, T val) {
        int id = lb(sorted, pair<ll, ll>(x, y));
        return update_(id, x, y, val);
    }
    T query(ll lx, ll ly, ll rx, ll ry) {
        int lxid = lb(sorted, pair<ll, ll>(lx, -INFL));
        int rxid = lb(sorted, pair<ll, ll>(rx, -INFL));
        return (lxid >= rxid) ? e() : query(lxid, rxid, ly, ry, 0, 0, n);
    }
};