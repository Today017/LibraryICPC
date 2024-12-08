template<class T, class U> T PowMod(T x, U n, T md) {
  T r = 1 % md;
  x %= md;
  while(n) {
    if(n & 1) r = (r * x) % md;
    x = (x * x) % md;
    n >>= 1;
  }
  return r;
}

bool IsPrime(ll n) {
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n % 2 == 0) return false;
  ll d = n - 1;
  while(d % 2 == 0) d /= 2;
  for(ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if(n <= a) break;
    ll t = d;
    ll y = PowMod<__int128_t>(a, t, n);  // over
    while(t != n - 1 && y != 1 && y != n - 1) {
      y = __int128_t(y) * y % n;  // flow
      t <<= 1;
    }
    if(y != n - 1 && t % 2 == 0) return false;
  }
  return true;
}

ll PollardSingle(ll n) {
  ll R;
  auto f = [&](ll x) { return (__int128_t(x) * x + R) % n; };
  if(IsPrime(n)) return n;
  if(n % 2 == 0) return 2;
  ll st = 0;
  while(true) {
    R = rnd(1, n);
    st++;
    ll x = st, y = f(x);
    while(true) {
      ll p = gcd((y - x + n), n);
      if(p == 0 || p == n) break;
      if(p != 1) return p;
      x = f(x);
      y = f(f(y));
    }
  }
}

vector<ll> Factor(ll n) {
  if(n == 1) return {};
  ll x = PollardSingle(n);
  if(x == n) return {x};
  vector<ll> l = Factor(x), r = Factor(n / x);
  l.insert(l.end(), r.begin(), r.end());
  return l;
}
