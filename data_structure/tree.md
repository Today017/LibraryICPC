[top](../README.md)

# [Sorted Tree](./tree.hpp)

`tree<T>(T not_found)`
- 順序付き集合を管理するデータ構造。 `not_found` は所望の値が見つからなかった場合に返す値として定義する。デフォルトは `INFL` 。

`T min()`
- 最小値を返す。
- $O(1)$

`T max()`
- 最大値を返す。
- $O(1)$

`T pop_min()`
- 最小値を返し、削除する。
- $O(\log n)$

`T pop_max()`
- 最大値を返し、削除する。
- $O(\log n)$

`bool contains(T x)`
- $x$ が含まれているか否かを返す。
- $O(\log n)$

`bool discard(T x)`
- $x$ を削除する。存在しない場合は `false` を返す。
- $O(\log n)$

`T gt(T x)`
- $x$ より大きい最小の値を返す。
- $O(\log n)$

`T ge(T x)`
- $x$ 以上で最小の値を返す。

`T lt(T x)`
- $x$ より小さい最大の値を返す。

`T le(T x)`
- $x$ 以下で最大の値を返す。

`int count_lt(T x)`
- $x$ 未満の要素の個数を返す。

`int count_le(T x)`
- $x$ 以下の要素の個数を返す。

`int count_gt(T x)`
- $x$ より大きい要素の個数を返す。

`int count_gt(T x)`
- $x$ 以上の要素の個数を返す。

`T kth_min(int k)`
- $k$ 番目に小さい値を返す。`0-indexed` であることに注意。

`T kth_max(int k)`
- $k$ 番目に大きい値を返す。