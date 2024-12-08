struct FenwickTree {
    vector<ll> a;
    FenwickTree(int n) : a(n + 1) {}
    void add(int i, ll x) {
        i++;
        while (i < a.size()) a[i] += x, i += i & -i;
    }
    ll sum(int i) {
        ll s = 0;
        while (i) s += a[i], i -= i & -i;
        return s;
    }
    ll sum(int l, int r) { return sum(r) - sum(l); }
};