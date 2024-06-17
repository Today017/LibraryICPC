template <typename T>
struct disjoint_sparse_table {
    using F = function<T(T, T)>;
    disjoint_sparse_table(const vector<T>& a, F f, T e) {
        n = a.size();
        this->f = f;
        dat.push_back(a);
        for (int i = 2; i < n; i <<= 1) {
            dat.push_back(vector<T>(n, e));
            for (int j = i; j < n; j += i << 1) {
                dat.back()[j - 1] = dat[0][j - 1];
                for (int k = 2; k <= i; k++) {
                    dat.back()[j - k] = f(dat[0][j - k], dat.back()[j - k + 1]);
                }
                dat.back()[j] = dat[0][j];
                for (int k = 2; k <= i && j + k <= n; k++) {
                    dat.back()[j + k - 1] = f(dat.back()[j + k - 2], dat[0][j + k - 1]);
                }
            }
        }
    }
    T query(int l, int r) {
        r--;
        if (l == r) {
            return dat[0][l];
        }
        int k = 31 - __builtin_clz(l ^ r);
        return f(dat[k][l], dat[k][r]);
    }

private:
    F f;
    int n;
    vector<vector<T>> dat;
};