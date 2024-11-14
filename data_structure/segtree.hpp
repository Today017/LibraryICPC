template <typename T, T (*op)(T, T), T (*e)()>
struct Segtree {
    int n;
    vector<T> node;
    Segtree(vector<int> a) {
        n = 1;
        while (n < (int)a.size()) n <<= 1;
        node.resize(2 * n, e());
        for (int i = 0; i < (int)a.size(); i++) node[i + n] = a[i];
        for (int i = n - 1; i > 0; i--) node[i] = op(node[i << 1], node[i << 1 | 1]);
    }
    void set(int i, T x) {
        i += n;
        node[i] = x;
        while (i) {
            i >>= 1;
            node[i] = op(node[i << 1], node[i << 1 | 1]);
        }
    }
    T prod(int l, int r) {
        T lv = e(), rv = e();
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) lv = op(lv, node[l++]);
            if (r & 1) rv = op(node[--r], rv);
            l >>= 1;
            r >>= 1;
        }
        return op(lv, rv);
    }
};