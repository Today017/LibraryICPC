struct LiChaoTree {
    static const ll INFL = 1LL << 60;
    struct line {
        ll a, b;
        line() : a(0), b(INFL) {}
        line(ll a, ll b) : a(a), b(b) {}
        ll get(ll x) { return a * x + b; }
        inline bool over(line r, ll x) { return get(x) < r.get(x); }
    };
    int n;

    vector<ll> x;
    vector<line> seg;
    LiChaoTree() {}
    LiChaoTree(const vector<ll>& _x) : x(_x) {
        sort(x.begin(), x.end());
        int n2 = x.size();
        n = 1;
        while (n < n2) n <<= 1;
        x.resize(n);
        for(int i = n2; i < n; i++) x[i] = x[n2 - 1];
        seg = vector<line>(n * 2);
    }
    void upd(line L, int i, int l, int r) {
        while (true) {
            int mid = l + r >> 1;
            bool lov = L.over(seg[i], x[l]);
            bool rov = L.over(seg[i], x[r - 1]);
            if (lov == rov) {
                if (lov) swap(seg[i], L);
                return;
            }
            bool mov = L.over(seg[i], x[mid]);
            if (mov) swap(seg[i], L);
            if (lov != mov) {
                i = (i << 1), r = mid;
            } else {
                i = (i << 1) + 1, l = mid;
            }
        }
    }
    void upd(line L, unsigned i) {
        int ub = bit_width(i) - 1;
        int l = (n >> ub) * (i - (1 << ub));
        int r = l + (n >> ub);
        upd(L, i, l, r);
    }
    void update(ll a, ll b) { upd(line(a, b), 1, 0, n); }
    void update_segment(ll l, ll r, ll a, ll b) {
        l = lower_bound(x.begin(), x.end(), l) - x.begin() + n;
        r = lower_bound(x.begin(), x.end(), r) - x.begin() + n;
        line L(a, b);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) upd(L, l++);
            if (r & 1) upd(L, --r);
        }
    }
    ll query(ll t) {
        ll k = lower_bound(x.begin(), x.end(), t) - x.begin() + n;
        k += n;
        ll res = seg[k].get(t);
        while (k > 1) {
            k >>= 1;
            res = min(res, seg[k].get(t));
        }
        return res;
    }
};