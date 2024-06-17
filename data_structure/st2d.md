[top](../README.md)

# [Sparse Table 2D](./st2d.hpp)

`void sparse_table_init(vector<vector<ll>> a, bool is_min=true)`
- 2 次元配列 `a` に対して 2 次元の Sparse Table を構築する。
- $O(hw\log{h}\log{w})$

`ll sparse_table_query(int l, int r, int u, int d)`
- 矩形領域 $[l, r) \times [u, d)$ における最小値を返す。
- $O(1)$