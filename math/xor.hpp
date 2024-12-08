template<typename T> void Fwt(vector<T>& f, bool inv = false) {
  int n = f.size(), m = __lg(n);
  for(int i = 0; i < m; i++) {
    for(int b = 0; b < n; b++) {
      if(~b >> i & 1) {
        T x = f[b], y = f[b ^ (1 << i)];
        f[b] = x + y;
        f[b ^ (1 << i)] = x - y;
      }
    }
  }
  if(inv) {
    T iz = T(1) / T(f.size());
    for(auto& e : f) e *= iz;
  }
}
