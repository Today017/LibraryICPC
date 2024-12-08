ll PrimitiveRoot(ll p) {
  auto v = Factor(p - 1);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  while(true) {
    ll g = rnd(1, p);
    bool ok = true;
    for(auto d : v) {
      ll f = (p - 1) / d;
      if(PowMod<__int128_t>(g, f, p) == 1) {
        ok = false;
        break;
      }
    }
    if(ok) return g;
  }
}
