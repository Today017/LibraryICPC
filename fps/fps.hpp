struct Fps {
  vector<mint> v;

  Fps(const vector<mint>& v = {}) : v(v) {}
  Fps(int n) : v(n) {}

  void shrink() {
    while (v.size() && !v.back()) v.pop_back();
  }

  void resize(int n) { v.resize(n); }

  int size() const { return int(v.size()); }

  mint freq(int p) const { return (p < size()) ? v[p] : 0; }

  mint& operator[](int k) { return v[k]; }

  void emplaceBack(mint x) { v.push_back(x); }

  Fps pre(int le) const { return {{v.begin(), v.begin() + min(size(), le)}}; }

  Fps operator-() const {
    vector<mint> res{v};
    for (auto& e : res) e = -e;
    return res;
  }

  Fps operator+(const Fps& r) const {
    int n = max(size(), r.size());
    vector<mint> res(n);
    for (int i = 0; i < n; i++) res[i] = freq(i) + r.freq(i);
    return res;
  }

  Fps operator-(const Fps& r) const { return (*this) + (-r); }

  Fps operator*(const Fps& r) const { return {mul(v, r.v)}; }

  Fps operator*(const mint& r) const {
    int n = size();
    vector<mint> res(n);
    for (int i = 0; i < n; i++) res[i] = v[i] * r;
    return res;
  }

  Fps operator/(const mint& r) const { return *this * (mint(1) / r); }

  Fps operator/(const Fps& r) const {
    if (size() < r.size()) return {};
    int n = size() - r.size() + 1;
    return (rev().pre(n) * r.rev().inv(n)).pre(n).rev();
  }

  Fps operator%(const Fps& r) const { return *this - *this / r * r; }

  Fps operator<<(int s) const {
    vector<mint> res(size() + s);
    for (int i = 0; i < size(); i++) res[i + s] = v[i];
    return res;
  }

  Fps operator>>(int s) const {
    if (size() <= s) return Fps();
    vector<mint> res(size() - s);
    for (int i = 0; i < size() - s; i++) res[i] = v[i + s];
    return res;
  }

  Fps& operator+=(const Fps& r) { return *this = *this + r; }
  Fps& operator-=(const Fps& r) { return *this = *this - r; }
  Fps& operator*=(const Fps& r) { return *this = *this * r; }
  Fps& operator*=(const mint& r) { return *this = *this * r; }
  Fps& operator/=(const Fps& r) { return *this = *this / r; }
  Fps& operator/=(const mint& r) { return *this = *this / r; }
  Fps& operator%=(const Fps& r) { return *this = *this % r; }
  Fps& operator<<=(int n) { return *this = *this << n; }
  Fps& operator>>=(int n) { return *this = *this >> n; }

  Fps rev(int n = -1) const {
    vector<mint> res = v;
    if (n != -1) res.resize(n);
    reverse(res.begin(), res.end());
    return res;
  }

  Fps diff() const {
    vector<mint> res(max(0, size() - 1));
    for (int i = 1; i < size(); i++) res[i - 1] = freq(i) * i;
    return res;
  }

  Fps integ() const {
    vector<mint> res(size() + 1);
    for (int i = 0; i < size(); i++) res[i + 1] = freq(i) / (i + 1);
    return res;
  }

  Fps inv(int m) const {
    Fps res = Fps({mint(1) / freq(0)});
    for (int i = 1; i < m; i *= 2) {
      res = (res * mint(2) - res * res * pre(2 * i)).pre(2 * i);
    }
    return res.pre(m);
  }

  Fps exp(int n) const {
    assert(freq(0) == 0);
    Fps g = Fps({1});
    for (int i = 1; i < n; i *= 2) {
      g = (g * (pre(i * 2) + Fps({1}) - g.log(i * 2))).pre(i * 2);
    }
    return g.pre(n);
  }

  Fps log(int n) const {
    assert(freq(0) == 1);
    auto f = pre(n);
    return (f.diff() * f.inv(n - 1)).pre(n - 1).integ();
  }

  Fps sqrt(int n) const {
    assert(freq(0) == 1);
    Fps f = pre(n + 1);
    Fps g({1});
    for (int i = 1; i < n; i *= 2) {
      g = (g + f.pre(2 * i) * g.inv(2 * i)) * mint((mod + 1) / 2);
    }
    return g.pre(n + 1);
  }

  Fps pow(ll k, ll n) {
    if (k == 0) {
      Fps res(n);
      res[0] = 1;
      return res;
    }
    for (int i = 0; i < size(); i++) {
      if ((*this)[i]) {
        mint rev = mint(1) / (*this)[i];
        Fps ret = (((*this * rev) >> i).log(n) * mint(k)).exp(n);
        ret *= (*this)[i].pow(k);
        ret = (ret << (i * k)).pre(n);
        if (ret.size() < n) ret.resize(n);
        return ret;
      }
      if ((i + 1) * k >= n) return Fps(n);
    }
    return Fps(n);
  }

  Fps pow_mod(ll n, const Fps& mod) {
    Fps x = *this, r = {{1}};
    while (n) {
      if (n & 1) r = r * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
    return r;
  }
};
