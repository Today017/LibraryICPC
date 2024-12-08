struct Edge {
  int x, y, idx;
};

vector<Edge> EulerianPath(vector<Edge> es, int s, bool directed = false) {
  if (es.empty()) return {};
  int n = 0;
  
  // 最大のノード番号を求める
  for (const auto& e : es) {
    n = max(n, max(e.x, e.y) + 1);
  }

  vector<vector<pair<Edge, int>>> g(n);

  // グラフを構築
  for (auto& e : es) {
    int p = g[e.y].size();
    g[e.x].emplace_back(e, p);
    
    if (!directed) {
      int q = g[e.x].size() - 1;
      swap(e.x, e.y);
      g[e.x].emplace_back(e, q);
    }
  }

  vector<Edge> ord;
  stack<pair<int, Edge>> st;
  st.emplace(s, Edge{-1, -1, -1});

  while (!st.empty()) {
    int x = st.top().first;
    
    if (g[x].empty()) {
      ord.push_back(st.top().second);
      st.pop();
    } else {
      auto e = g[x].back();
      g[x].pop_back();
      if (e.second == -1) continue;
      if (!directed) g[e.first.y][e.second].second = -1;
      st.emplace(e.first.y, e.first);
    }
  }

  ord.pop_back();
  reverse(ord.begin(), ord.end());

  if (ord.size() != es.size()) return {};
  return ord;
}
