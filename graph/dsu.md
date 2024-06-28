[top](../README.md)

# [Disjoint Set Union](./dsu.hpp)

`disjoint_set_union(int n)`

`int find(int x)`
- 頂点 $x$ を含む連結成分の代表元。
- $O(\alpha(n))$

`void unite(int x, int y)`
- 頂点 $x$, $y$ を連結する。
- $O(\alpha(n))$

`int size(int x)`
- 頂点 $x$ を含む連結成分のサイズ。
- $O(1)$

`bool same(int x, int y)`
- 頂点の組 $(x, y)$ が連結であるか否か。
- $O(\alpha(n))$

`vector<vector<int>> groups`
- 連結成分ごとに所属する頂点を返す。
- $O(N)$
