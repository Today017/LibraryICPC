template <typename T>
struct fenwick_tree {
    fenwick_tree() = default;
    fenwick_tree(int n) {
        this->n = n;
        dat = vector<T>(n);
    }
    void add(int i, T x) {
        i++;
        while (i <= n) {
            dat[i - 1] += x;
            i += i & -i;
        }
    }
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
    T operator[](int i) {
        return sum(i, i + 1);
    }
    int size() {
        return n;
    }

private:
    int n;
    vector<T> dat;
    T sum(int r) {
        T ret = 0;
        while (r > 0) {
            ret += dat[r - 1];
            r -= r & -r;
        }
        return ret;
    }
};
