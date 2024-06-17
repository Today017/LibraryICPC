int longest_increasing_subsequence_length(vector<int> &a, bool strict = true) {
    int n = a.size();
    vector<int> dp(n, INF);
    for (int i = 0; i < n; i++) {
        vector<int>::iterator itr;
        if (strict) {
            itr = lower_bound(dp.begin(), dp.end(), a[i]);
        } else {
            itr = upper_bound(dp.begin(), dp.end(), a[i]);
        }
        *itr = a[i];
    }
    return find(dp.begin(), dp.end(), INF) - dp.begin();
}
