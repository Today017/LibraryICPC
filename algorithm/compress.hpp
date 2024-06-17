template <typename T>
vector<ll> compress(vector<T> &a) {
    int n = a.size();
    vector<ll> ret(n);
    for (int i = 0; i < n; i++) {
        ret[i] = a[i];
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(ret.begin(), ret.end(), a[i]) - ret.begin();
    }
    return ret;
}
