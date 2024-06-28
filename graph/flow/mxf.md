[top](../../README.md)

# [Max Flow](./mxf.hpp)

`max_flow<Cap>(int n)`

`void add_edge(int u, int v, Cap c)`
- 頂点 $u$ から $v$ へ 容量 $c$ の辺を追加する。

`Cap get(int start, int goal)`
- 頂点 $start$ から $goal$ への最大流を返す。
- Dinic 法を用いている。
- $O(V^2 E)$