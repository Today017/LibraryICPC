struct mo_algorithm {
    mo_algorithm(int n, int q) {
        max_n = 1 << 25;
        query_count = 0;
        this->n = n;
        this->q = q;
    }
    void add_query(int l, int r) {
        query_count++;
        ls.push_back(l);
        rs.push_back(r);
    }
    template <typename F1, typename F2, typename F3, typename F4, typename F5>
    void run(F1 &&add_left, F2 &&add_right, F3 &&del_left, F4 &&del_right, F5 &&out) {
        assert(q == query_count);
        vector<int> qi(q);
        iota(qi.begin(), qi.end(), 0);
        vector<ll> eval(q);
        for (int i = 0; i < q; i++) {
            eval[i] = hilbertorder(ls[i], rs[i]);
        }
        sort(qi.begin(), qi.end(), [&](int i, int j) {
            return eval[i] < eval[j];
        });
        int nl = 0, nr = 0;
        for (int &i : qi) {
            while (nl > ls[i]) {
                add_left(--nl);
            }
            while (nr < rs[i]) {
                add_right(nr++);
            }
            while (nl < ls[i]) {
                del_left(nl++);
            }
            while (nr > rs[i]) {
                del_right(--nr);
            }
            out(i);
        }
    }

private:
    int n, q, query_count;
    ll max_n;
    vector<int> ls, rs;
    ll hilbertorder(int x, int y) {
        ll rx, ry, d = 0;
        for (ll s = max_n >> 1ll; s; s >>= 1ll) {
            rx = (x & s) > 0, ry = (y & s) > 0;
            d += s * s * ((rx * 3) ^ ry);
            if (ry) {
                continue;
            }
            if (rx) {
                x = max_n - 1 - x;
                y = max_n - 1 - y;
            }
            swap(x, y);
        }
        return d;
    }
};
