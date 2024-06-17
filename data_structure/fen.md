[top](../README.md)

# [Fenwick Tree](./fen.hpp)

`T add(int i, T x)`
- 要素 $i$ に $x$ を加算する。
- $O(\log n)$

`T sum(int l, int r)`
- $[l, r)$ の和を返す。
- $O(\log n)$

`T operator[](int i)`
- 要素 $i$ を取得する。
- $O(\log n)$

`int size()`
- Fenwick Tree のサイズを返す。


### 区間加算1点取得を行う場合
```cpp
fenwick_tree<int> ft(N + 1);

// [l, r]に区間加算
ft.add(l, x);
ft.add(r + 1, x);

// i番目を取得
ft.sum(i + 1);
```