
const ll mod = (1LL << 61) - 1;

ll add(ll a, ll b) { return (a += b) >= mod ? a - mod : a; }

ll mul(ll a, ll b) {
  __int128_t c = (__int128_t)a * b;
  return add(c >> 61, c & mod);
}

ll r = 7954398468495;

struct Rh {
  ll n;
  vector<ll> hs, pw;

  Rh(string s) : n(s.size()), hs(n + 1), pw(n + 1, 1) {
    for (int i = 0; i < n; ++i) {
      pw[i + 1] = mul(pw[i], r);
      hs[i + 1] = add(mul(hs[i], r), s[i]);
    }
  }

  ll get(ll l, ll r) const { return add(hs[r], mod - mul(hs[l], pw[r - l])); }

  int lcp(int i, int j) {
    int ok = 0, ng = min(n - i, n - j) + 1;
    while (ok < ng - 1) {
      int mid = (ok + ng) >> 1;
      ((get(i, i + mid) == get(j, j + mid)) ? ok : ng) = mid;
    }
    return ok;
  }
};