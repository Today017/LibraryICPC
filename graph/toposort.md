[top](../README.md)

# [Topological Sort](./toposort.hpp)

`vector<int> topological_sort(const vector<vector<int>> &G)`
- グラフ $G$ に対して、トポロジカルソートを行う。
- グラフが DAG でない場合、配列のサイズが $V$ より小さくなる。
- $O(V + E)$