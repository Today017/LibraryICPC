[top](../README.md)

# [Sparse Table](./spt.hpp)

`sparse_table<T, MIN>`
- 配列 $a$ から Sparse Table を構築する。
- $O(n\log{n})$

`T query(int l, int r)`
- $\min(a_l, a_{l+1}, ... , a_{r-1})$ を返す。
- $O(1)$