[top](../../README.md)

# [Dijkstra](./dij.hpp)

`vector<T> dijkstra(vector<vector<pair<int, T>>> G, int start, T inf)`
- グラフ $G$ に対して、頂点 $start$ からの各頂点への最短距離を返す。
- $O(E\log{E})$