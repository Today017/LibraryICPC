template<typename G>
struct Ll {
  int n;
  const G g;
  vector<int> ord, low, arti;
  vector<pair<int, int>> bridge;

  Ll(G g) : n(g.size()), g(g), ord(g.size(), -1), low(g.size(), -1) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
      if (ord[i] == -1) k = dfs(i, k, -1);
    }
  }

  int dfs(int x, int k, int p) {
    low[x] = (ord[x] = k++);
    int cnt = 0;
    bool is_arti = false, second = false;
    for (const auto& e : g[x]) {
      if (ord[e] == -1) {
        cnt++;
        k = dfs(e, k, x);
        low[x] = min(low[x], low[e]);
        is_arti |= (p != -1) && (low[e] >= ord[x]);
        if (ord[x] < low[e]) bridge.push_back(minmax(x, e));
      } else if (e != p || second) {
        low[x] = min(low[x], ord[e]);
      } else {
        second = true;
      }
    }
    is_arti |= p == -1 && cnt > 1;
    if (is_arti) arti.push_back(x);
    return k;
  }
};
