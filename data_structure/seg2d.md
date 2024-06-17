[top](../README.md)

# [Segment Tree 2D](./seg2d.hpp)

`segment_tree_2D<T>(int h, int w, F f, T e)`
- サイズ $h\times w$ ,演算 $f$, 単位元 $e$ の Segment Tree を構築する。
- 集合 $T$, 演算 $f$, 単位元 $e$ が単位半群を為すことを要求する。
- $O(hw)$

`void set(int x, int y, T v)`
- 位置 $(x, y)$ の要素を $v$ に変える。
- $O(\log{h}\log{w})$

`T query(int l, int r, int u, int d)`
- 矩形領域 $[l, r) \times [u, d)$ に対しての演算結果を返す。
- $O(\log{h}\log{w})$