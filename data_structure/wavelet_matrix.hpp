#define U uint32_t
#define L uint64_t
struct BitVector {
    static constexpr U w = 64;
    vector<L> b;
    vector<U> c;
    int n, z;
    inline U get(U i) const { return U(b[i / w] >> (i % w)) & 1; }
    inline void set(U i) { b[i / w] |= 1ULL << (i % w); }
    BitVector() {}
    BitVector(int n) { init(n); }
    void init(int _n) {
        n = z = _n;
        b.assign(n / w + 1, 0);
        c.assign(b.size(), 0);
    }
    void build() {
        for (int i = 1; i < b.size(); i++) c[i] = c[i - 1] + __builtin_popcountll(b[i - 1]);
        z = rank0(n);
    }
    inline U rank0(U i) const { return i - rank1(i); }
    inline U rank1(U i) const { return c[i / w] + __builtin_popcountll(b[i / w] & ((1ULL << (i % w)) - 1)); }
};

template <typename T, const int lg = 31>
struct WaveletMatrix {
    int n;
    vector<T> a;
    array<BitVector, lg> bv;
    WaveletMatrix(const vector<T> &_a) : n(_a.size()), a(_a) { build2(); }
    void build() {
        for (int i = 0; i < lg; i++) bv[i] = BitVector(n);
        vector<T> cur = a, nxt(n);
        for (int h = lg - 1; h >= 0; h--) {
            for (int i = 0; i < n; i++) if (cur[i] >> h & 1) bv[h].set(i);
            bv[h].build();
            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].z};
            for (int i = 0; i < n; i++) *it[bv[h].get(i)]++ = cur[i];
            swap(cur, nxt);
        }
        return;
    }
    inline pair<U, U> succ0(int l, int r, int h) const { return {bv[h].rank0(l), bv[h].rank0(r)}; }
    inline pair<U, U> succ1(int l, int r, int h) const {
        U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r), z = bv[h].z;
        return {l + z - l0, r + z - r0};
    }
    T access(U k) const {
        T ret = 0;
        for (int h = lg - 1; h >= 0; h--) {
            U f = bv[h].get(k);
            ret |= f ? T(1) << h : 0;
            k = f ? bv[h].rank1(k) + bv[h].z : bv[h].rank0(k);
        }
        return ret;
    }
    T kth_smallest(U l, U r, U k) const {
        T ret = 0;
        for (int h = lg - 1; h >= 0; h--) {
            U l0 = vb[h].rank0(l), r0 = bv[h].rank0(r);
            if (k < r0 - l0) l = l0, r = r0;
            else {
                k -= r0 - l0;
                ret |= T(1) << h;
                l += bv[h].z - l0, r += bv[h].z - r0;
            }
        }
        return ret;
    }
    T kth_largest(U l, U r, U k) const { return kth_smallest(l, r, r - l - k); }
    int range_freq(int l, int r, T upper) {
        if (upper >= (T(1) << lg)) return r - l;
        int ret = 0;
        for (int h = lg - 1; h >= 0; h--) {
            bool f = upper >> h & 1;
            U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if (f) ret += r0 - l0, l += bv[h].z - l0, r += bv[h].z - r0;
            else l = l0, r = r0;
        }
        return ret;
    }
    int range_freq(int l, int r, T lower, T upper) { return range_freq(l, r, upper) - range_freq(l, r, lower); }
    array<vector<ll>, lg> sums;
    vector<ll> acc;
    void build2() {
        for (int i = 0; i < lg; i++) bv[i] = BitVector(n), sum[i].assign(n + 1, 0);
        acc.resize(a.size() + 1);
        vector<T> cur = a, nxt(n);
        for (int h = lg - 1; h >= 0; h--) {
            for (int i = 0; i < n; i++) if (cur[i] >> h & 1) bv[h].set(i);
            bv[h].build();
            array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt) + bv[h].z};
            for (int i = 0; i < N; i++) *it[bv[h].get(i)]++ = cur[i];
            swap(cur, nxt);
            for (int i = 0; i < n; i++) sum[h][i + 1] = sum[h][i] + (cur[i] >> h & 1);
        }
        for (int i = 0; i < n; i++) acc[i + 1] = acc[i] + a[i];
    }
    ll bottom_k_sum(int l, int r, int k) {
        ll ret = 0;
        for (int h = lg - 1; h >= 0; h--) {
            U l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
            if (k < r0 - l0) l = l0, r = r0;
            else ret += sum[h][r] - sum[h][l], k -= r0 - l0, l += bv[h].z - l0, r += bv[h].z - r0;
        }
        ret += sums[0][l + k] - sums[0][l];
        return ret;
    }
    ll top_k_sum(int l, int r, int k) { return acc[r] - acc[l] - bottom_k_sum(l, r, r - l - k); }
};
#undef U
#undef L