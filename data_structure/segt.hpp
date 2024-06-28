template <typename T>
struct segment_tree {
    using F = function<T(T, T)>;
    segment_tree() = default;
    segment_tree(int n, F f, T e) {
        this->n = n;
        this->f = f;
        this->e = e;
        dat = vector<T>(n << 1, e);
    }
    void build(const vector<T> &a) {
        assert((int)a.size() == n);
        for (int i = 0; i < (int)a.size(); i++) {
            dat[i + n] = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            dat[i] = f(dat[i << 1], dat[i << 1 | 1]);
        }
    }
    void set(int i, T x) {
        assert(0 <= i && i < n);
        i += n;
        dat[i] = x;
        while (i) {
            i >>= 1;
            dat[i] = f(dat[i << 1], dat[i << 1 | 1]);
        }
    }
    T query(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        l += n;
        r += n;
        T ret = e;
        while (l < r) {
            if (l & 1) {
                ret = f(ret, dat[l]);
                l++;
            }
            if (r & 1) {
                r--;
                ret = f(ret, dat[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
    T operator[](int i) {
        assert(0 <= i && i < n);
        return dat[n + i];
    }
    int size() {
        return n;
    }

private:
    int n;
    F f;
    T e;
    vector<T> dat;
};

template <typename T>
segment_tree<T> range_max_query(int n, T e) {
    return segment_tree<T>(n, [](T a, T b) { return max(a, b); }, e);
}
template <typename T>
segment_tree<T> range_min_query(int n, T e) {
    return segment_tree<T>(n, [](T a, T b) { return min(a, b); }, e);
}
segment_tree<ll> range_sum_query(int n) {
    return segment_tree<ll>(n, [](ll a, ll b) { return a + b; }, 0);
}
