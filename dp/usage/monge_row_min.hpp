// A[N + 1][N + 1]: Monge が i > j のみ存在しているとき、i (= 0, ..., N)行目の最小値を返す
// f(i, j, v) で、j 行目の最小値が求まっている v を用いて、A[i][j] にアクセス
template <typename T, typename F>
vector<T> mongeRowMin(int n, const F& f) {
  vector<T> mv(n + 1, numeric_limits<T>::max()); // 各行の最小値
  mv[0] = 0;                                    // 初期値
  vector<int> mi(n + 1);                        // 各行の最小値列

  auto chk = [&](int i, int j) {
    if (mv[i] > f(i, j, mv)) mv[i] = f(i, j, mv), mi[i] = j;
  };

  chk(n, 0); // 最後の行を初期化

  auto solve = [&](auto&& self, int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) / 2;
    for (int k = mi[l]; k <= mi[r]; ++k) chk(m, k);
    self(self, l, m);
    for (int k = l + 1; k <= m; ++k) chk(r, k);
    self(self, m, r);
  };

  solve(solve, 0, n);
  return mv;
}
