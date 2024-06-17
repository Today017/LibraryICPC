[top](../README.md)

# [Disjoint Sparse Table](./dst.hpp)

`disjoint_sparse_table<T>(vector<T> a, F f, T e)`
- 配列 $a$ から 演算 $f$, 単位元 $e$ の Disjoint Sparse Table を構築する。
- 集合 $T$, 演算 $f$, 単位元 $e$ が単位半群を為すことを要求する。
- $O(n\log{n})$

`T query(int l, int r)`
- 区間 $[l, r)$ に対しての演算結果を返す。
- $O(1)$