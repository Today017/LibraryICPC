template <typename T>
struct sorted_array {
    vector<T> dat, dat_unique;
    T not_found;
    sorted_array() = default;
    sorted_array(const vector<T> &a, T not_found = -1) {
        dat = a;
        dat_unique = a;
        sort(dat_unique.begin(), dat_unique.end());
        dat = a;
        dat_unique.erase(unique(dat_unique.begin(), dat_unique.end()), dat_unique.end());
        this->not_found = not_found;
    }
    bool contains(T x) {
        return binary_search(dat.begin(), dat.end(), x) != dat.end();
    }
    T min() {
        return dat[0];
    }
    T max() {
        return dat[dat.size() - 1];
    }
    T gt(T x) {
        auto itr = upper_bound(dat_unique.begin(), dat_unique.end(), x);
        if (itr == dat_unique.end()) {
            return not_found;
        }
        return *itr;
    }
    T ge(T x) {
        auto itr = lower_bound(dat_unique.begin(), dat_unique.end(), x);
        if (itr == dat_unique.end()) {
            return not_found;
        }
        return *itr;
    }
    T lt(T x) {
        auto itr = lower_bound(dat_unique.begin(), dat_unique.end(), x);
        if (itr == dat_unique.begin()) {
            return not_found;
        }
        return *--itr;
    }
    T le(T x) {
        auto itr = upper_bound(dat_unique.begin(), dat_unique.end(), x);
        if (itr == dat_unique.begin()) {
            return not_found;
        }
        return *--itr;
    }
    int count_gt(T x) {
        return dat.end() - upper_bound(dat.begin(), dat.end(), x);
    }
    int count_ge(T x) {
        return dat.end() - lower_bound(dat.begin(), dat.end(), x);
    }
    int count_lt(T x) {
        return lower_bound(dat.begin(), dat.end(), x) - dat.begin();
    }
    int count_le(T x) {
        return upper_bound(dat.begin(), dat.end(), x) - dat.begin();
    }
    int count_range(T l, T r) {
        return count_ge(l) - count_gt(r);
    }
    int count_gt_unique(T x) {
        return dat_unique.end() - upper_bound(dat_unique.begin(), dat_unique.end(), x);
    }
    int count_ge_unique(T x) {
        return dat_unique.end() - lower_bound(dat_unique.begin(), dat_unique.end(), x);
    }
    int count_lt_unique(T x) {
        return lower_bound(dat_unique.begin(), dat_unique.end(), x) - dat_unique.begin();
    }
    int count_le_unique(T x) {
        return upper_bound(dat_unique.begin(), dat_unique.end(), x) - dat_unique.begin();
    }
    int count_range_unique(T l, T r) {
        return count_ge_unique(l) - count_gt_unique(r);
    }
    T kth_min(int k) {
        if (k < 0 || k >= (int)dat.size()) {
            return not_found;
        }
        return dat[k];
    }
    T kth_min_unique(int k) {
        if (k < 0 || k >= (int)dat_unique.size()) {
            return not_found;
        }
        return dat_unique[k];
    }
    T kth_max(int k) {
        if (k < 0 || k >= (int)dat.size()) {
            return not_found;
        }
        return dat[dat.size() - k - 1];
    }
    T kth_max_unique(int k) {
        if (k < 0 || k >= (int)dat_unique.size()) {
            return not_found;
        }
        return dat_unique[dat_unique.size() - k - 1];
    }
    int count(T x) {
        return count_ge(x) - count_gt(x);
    }
    int index(T x) {
        if (!find(x)) {
            return -1;
        }
        return lower_bound(dat.begin(), dat.end(), x) - dat.begin();
    }
    int size() {
        return dat.size();
    }
    int size_unique() {
        return dat_unique.size();
    }
};
