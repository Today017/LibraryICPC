template<typename G> 
struct Bcc : Ll<G> {
  vi used;
  vector<vector<Pii>> bc;
  vector<Pii> tmp;
  using L = Ll<G>;
  using L::g;
  using L::low;
  using L::ord;

  Bcc(G g) : L(g) { build(); }

  void build() {
    used.assign(si(g), 0);
    for (int i = 0; i < si(used); ++i) {
      if (!used[i]) dfs(i, -1);
    }
  }

  void dfs(int x, int p) {
    used[x] = true;
    for (auto e : g[x]) {
      if (e == p) continue;
      if (!used[e] || ord[e] < ord[x]) tmp.push_back(minmax(x, e));
      if (!used[e]) {
        dfs(e, x);
        if (low[e] >= ord[x]) {
          bc.push_back({});
          while (true) {
            auto p = tmp.back();
            bc.back().push_back(p);
            tmp.pop_back();
            if (p.first == min(x, e) && p.second == max(x, e)) break;
          }
        }
      }
    }
  }
};
