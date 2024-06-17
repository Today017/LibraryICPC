[top](../../README.md)

# [Bellman Ford](./bf.hpp)

`pair<bool, vector<ll>> bellman_ford(vector<vector<int, ll>> G, int start)`
- グラフ $G$ に対して頂点 $start$ からの各頂点への最短距離を格納した配列と、負のサイクルが存在するか否かを返す。
- $O(VE)$

## 負のサイクルが存在するときの注意点

負のサイクルが存在する場合、 $start$ からある頂点に向かう際に $start$ -> 負のサイクル -> 頂点 なるパスが存在するなら最短距離は -inf 、そうでない場合は返り値の配列の値となる。

よって、そのようなパスが存在するかの判定をする必要がある事に注意すること。

これは、逆辺を張ったグラフに対し BFS を行って $start$ から到達可能であるかを調べ、到達可能な頂点のみで更新を行うようにすることで実現可能。

[参考 1](https://yukicoder.me/submissions/967952)

[参考 2](https://mhrb-minase.hatenablog.com/entry/2019/08/20/003915)