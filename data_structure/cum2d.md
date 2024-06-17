[top](../README.md)

# [Cumulative Sum 2D](./cum2d.hpp)

`cumulative_sum_2D<U, T>(vector<vector<U>> a)`
- 行列 $a$ に対する2次元累積和を構築する。
- $O(hw)$

`T sum(int l, int r, int u, int d)`
- 矩形領域 $[l, r) \times [u, d)$ における累積和を返す。
- $O(1)$