struct ExtendedBlockCutTree {
  int n, cnt;
  vector<vector<int>> g;
  
  ExtendedBlockCutTree(vector<vector<int>>& e) {
    n = e.size();
    vector<int> next(n, -1);
    vector<int> d(n, -1);
    vector<int> imos(n, 0);
    
    for (int i = 0; i < n; ++i) {
      if (d[i] == -1) {
        d[i] = 0;
        dfs1(e, next, d, imos, i);
      }
    }
    
    cnt = 0;
    g.resize(n + 1);
    vector<bool> used(n, false);
    
    for (int i = 0; i < n; ++i) {
      if (d[i] == 0) dfs2(e, d, imos, used, cnt, i);
      if (e[i].empty()) {
        g[i].push_back(n + cnt);
        g[n + cnt].push_back(i);
        cnt++;
        g.push_back({});
      }
    }
    
    g.pop_back();
  }
  
  void dfs1(vector<vector<int>>& e, vector<int>& next, vector<int>& d, vector<int>& imos, int v) {
    for (int w : e[v]) {
      if (d[w] == -1) {
        d[w] = d[v] + 1;
        next[v] = w;
        dfs1(e, next, d, imos, w);
        imos[v] += imos[w];
      } else if (d[w] < d[v] - 1) {
        imos[v]++;
        imos[next[w]]--;
      }
    }
  }
  
  void dfs2(vector<vector<int>>& e, vector<int>& d, vector<int>& imos, vector<bool>& used, int b, int v) {
    used[v] = true;
    bool ok = false;
    
    for (int w : e[v]) {
      if (d[w] == d[v] + 1 && !used[w]) {
        if (imos[w] > 0) {
          if (!ok) {
            ok = true;
            g[v].push_back(n + b);
            g[n + b].push_back(v);
          }
          dfs2(e, d, imos, used, b, w);
        } else {
          g[v].push_back(n + cnt);
          g[n + cnt].push_back(v);
          cnt++;
          g.push_back({});
          dfs2(e, d, imos, used, cnt - 1, w);
        }
      }
    }
    
    if (!ok && d[v] > 0) {
      g[v].push_back(n + b);
      g[n + b].push_back(v);
    }
  }
  
  int size() { return g.size(); }
  vector<int>& operator[](int v) { return g[v]; }
};
