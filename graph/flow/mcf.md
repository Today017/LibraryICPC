[top](../../README.md)

# [Min Cost Flow](./mcf.hpp)

`min_cost_flow<Cap, Cost>(int n)`

`void add_edge(int u, int v, Cap cap, Cost cost)`
- 頂点 $u$ から $v$ へ 容量 $cap$, コスト $cost$ の辺を追加する。

`Cost get(int start, int goal, Cap flow)`
- 頂点 $start$ から $goal$ へ流量 $flow$ の最小費用流を流す。流せる場合はそのコスト、流せない場合は $inf$ を返す。
- Bellman Ford 法を用いている。
- $O(flow V E)$