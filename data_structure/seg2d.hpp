template <typename T>
struct segment_tree_2D {
    using F = function<T(T, T)>;
    segment_tree_2D(int h, int w, F f, T fe) {
        this->f = f;
        this->fe = fe;
        this->h = h;
        this->w = w;
        dat = vector<vector<T>>(this->h * 2, vector<T>(this->w * 2, fe));
    }
    void set(int x, int y, T v) {
        x += h;
        y += w;
        dat[x][y] = v;
        for (int i = x >> 1; i > 0; i >>= 1) {
            dat[i][y] = f(dat[i << 1][y], dat[i << 1 | 1][y]);
        }
        while (x > 0) {
            for (int j = y >> 1; j > 0; j >>= 1) {
                dat[x][j] = f(dat[x][j << 1], dat[x][j << 1 | 1]);
            }
            x >>= 1;
        }
    }
    T query(int l, int r, int u, int d) {
        T ret = fe;
        l += h;
        r += h;
        u += w;
        d += w;
        while (l < r) {
            if (l & 1) {
                ret = f(ret, query_sub(l, u, d));
                l++;
            }
            if (r & 1) {
                r--;
                ret = f(ret, query_sub(r, u, d));
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }

private:
    int h, w;
    vector<vector<T>> dat;
    F f;
    T fe;
    T query_sub(int x, int u, int d) {
        T ret = fe;
        while (u < d) {
            if (u & 1) {
                ret = f(ret, dat[x][u]);
                u++;
            }
            if (d & 1) {
                d--;
                ret = f(ret, dat[x][d]);
            }
            u >>= 1;
            d >>= 1;
        }
        return ret;
    }
};
