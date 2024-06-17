[top](../README.md)

# [Insertable Reversible Array](./insrev.hpp)

`insertable_reversible_array<T>(int n)`
`insertable_reversible_array<T>(vector<T> a)`
- Insertable Reversible Array は挿入・削除・区間反転可能な配列である。

`void insert(int i, T x)`
- $i$ 番目に $x$ を挿入する。
- $O(\log n)$

`void erase(int i)`
- $i$ 番目の要素を削除する。
- $O(\log n)$

`void reverse(int i, int j)`
- 区間 $[i, j)$ の要素を反転する。
- $O(\log n)$

`T get(i)`
- $i$ 番目の要素を取得する。
- $O(\log n)$

`void set(int i, T x)`
- $i$ 番目の要素を $x$ に変更する。
- $O(\log n)$

`int size()`
- 配列のサイズを取得する。
- $O(1)$
