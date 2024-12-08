template<typename T, typename F>
vector<pair<int, T>> monotoneMinima(int h, int w, const F& f) {
  vector<pair<int, T>> dp(h, {-1, T()});
  
  auto rec = [&](auto&& self, int u, int d, int l, int r) {
    if (u > d) return;
    int m = (u + d) / 2;
    auto& [idx, mi] = dp[m];
    idx = l, mi = f(m, l);
    for (int i = l + 1; i <= r; ++i) if (mi > f(m, i)) idx = i, mi = f(m, i);
    self(self, u, m - 1, l, idx);
    self(self, m + 1, d, idx, r);
  };
  
  rec(rec, 0, h - 1, 0, w - 1);
  return dp;
}