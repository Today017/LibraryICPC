template<typename T>
T LagrangePolynomial(const vector<T>& y, long long t) {
  int n = y.size() - 1;
  if (t <= n) return y[t];
  T ret(0);
  vector<T> dp(n + 1, 1), pd(n + 1, 1);

  for (int i = 0; i < n; ++i) dp[i + 1] = dp[i] * (t - i);
  for (int i = n; i >= 1; --i) pd[i - 1] = pd[i] * (t - i);

  for (int i = 0; i <= n; ++i) {
    T tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[n - i];
    ret -= ((n - i) & 1 ? tmp : -tmp);
  }

  return ret;
}
