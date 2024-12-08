template<typename T> struct M {
  vector<vector<T>> a;
  int n, m;
  M(int n, int m) : n(n), m(m), a(n, vector<T>(m)) {}
  M(int n = 0) : M<T>(n, n) {}
  vector<T>& operator[](int k) { return a[k]; }
  const vector<T>& operator[](int k) const { return a[k]; }
  
  static M I(int n) {
    M mat(n);
    for (int i = 0; i < n; i++) mat[i][i] = 1;
    return mat;
  }

  M& operator+=(const M& b) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        (*this)[i][j] += b[i][j];
      }
    }
    return *this;
  }

  M& operator-=(const M& b) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        (*this)[i][j] -= b[i][j];
      }
    }
    return *this;
  }

  M& operator*=(const M& b) {
    int l = b.m;
    vector<vector<T>> c(n, vector<T>(l));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < l; k++) {
          c[i][k] += (*this)[i][j] * b[j][k];
        }
      }
    }
    a.swap(c);
    return *this;
  }

  M& operator^=(long long k) {
    M b = M::I(n);
    while(k) {
      if(k & 1) b *= *this;
      *this *= *this;
      k >>= 1;
    }
    a.swap(b.a);
    return *this;
  }

  M operator+(const M& b) const { return (M(*this) += b); }
  M operator-(const M& b) const { return (M(*this) -= b); }
  M operator*(const M& b) const { return (M(*this) *= b); }
  M operator^(const M& b) const { return (M(*this) ^= b); }
};

template<typename T> pair<int, T> GaussElimination(M<T>& a, bool LE = false) {
  int n = a.n, m = a.m;
  int rank = 0, je = LE ? m - 1 : m;
  mint det = 1;

  for (int j = 0; j < je; j++) {
    int idx = -1;
    for (int i = rank; i < n; i++) {
      if(a[i][j].x) {
        idx = i;
        break;
      }
    }
    if(idx == -1) {
      det = 0;
      continue;
    }
    if(rank != idx) {
      det = -det;
      swap(a[rank], a[idx]);
    }
    det *= a[rank][j];
    if(LE && a[rank][j].x != 1) {
      mint coeff = a[rank][j].inv();
      for (int k = j; k < m; k++) a[rank][k] *= coeff;
    }
    int is = LE ? 0 : rank + 1;
    for (int i = is; i < n; i++) {
      if(i == rank) continue;
      if(a[i][j].x) {
        mint coeff = a[i][j] / a[rank][j];
        for (int k = j; k < m; k++) a[i][k] -= a[rank][k] * coeff;
      }
    }
    rank++;
  }
  return make_pair(rank, det);
}

template<typename T> vector<vector<T>> LinearEquation(M<T> a, vector<T> b) {
  int n = a.n, m = a.m;
  for (int i = 0; i < n; i++) a[i].push_back(b[i]);
  a.m++;
  auto p = GaussElimination(a, true);
  int rank = p.first;

  for (int i = rank; i < n; i++) {
    if(a[i][m].x != 0) return {};
  }

  vector<vector<T>> res(1, vector<T>(m));
  vi piv(m, -1);
  int j = 0;
  
  for (int i = 0; i < rank; i++) {
    while(a[i][j].x == 0) ++j;
    res[0][j] = a[i][m], piv[j] = i;
  }

  for (int j = 0; j < m; j++) {
    if(piv[j] == -1) {
      vector<T> x(m);
      x[j] = 1;
      for (int k = 0; k < j; k++) {
        if(piv[k] != -1) x[k] = -a[piv[k]][j];
      }
      res.push_back(x);
    }
  }
  return res;
}
