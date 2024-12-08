template<bool is_or, typename T>
void Fzt(vector<T>& a, bool inv = false) {
  int n = a.size();
  int m = __lg(n);
  for (int i = 0; i < m; ++i) {
    for (int b = 0; b < n; ++b) {
      if ((b >> i & 1) == is_or) {
        a[b] += a[b ^ (1 << i)] * (inv ? -1 : 1);
      }
    }
  }
}
