[top](../README.md)

# [SCC Decomposition](./scc.hpp)

`auto scc_decomposition(const vector<vector<int>> G)`
- グラフ $G$ に対して強連結成分分解をする。
- $($ 各連結成分に属する頂点, SCC 後のグラフ, 各頂点の属する連結成分 $)$ を返す。
- $O(V + E)$