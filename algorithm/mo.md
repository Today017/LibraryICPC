[top](../README.md)

# [Mo](./mo.hpp)

[参考](https://ei1333.hateblo.jp/entry/2017/09/11/211011)

`mo_algorithm(int n, int q)`

`void add_query(int l, int r)`
- 区間 $[l, r)$ に対するクエリを追加する。

`void run(F1 add_left, F2 add_right, F3 del_left, F4 del_right, F5 out)`
- $O(n\sqrt{q})$

### 解説
配列に対する区間クエリを処理する。
以下の条件を満たす場合、 Mo を適用できる可能性がある。

1. 配列の要素が不変。
2. クエリを先読みできる。
3. 区間 $[l, r)$ の結果から 区間 $[l+1, r), [l-1, r), [l, r-1), [l,r+1)$ の結果を容易に計算できる。

`run` で実行する各関数は次のように実装する。

`add_left(int i)`
- $i$ 番目の要素が左から加わるときの処理。 $[l, r)$ の結果から $[l-1, r)$ の結果を計算する。

`add_right(int i)`
- $i$ 番目の要素が右から加わるときの処理。 $[l, r)$ の結果から $[l, r+1)$ の結果を計算する。

`del_left(int i)`
- $i$ 番目の要素が左から消えるときの処理。 $[l, r)$ の結果から $[l+1, r)$ の結果を計算する。

`del_right(int i)`
- $i$ 番目の要素が右から消えるときの処理。 $[l, r)$ の結果から $[l, r-1)$ の結果を計算する。

`out(int idx)`
- $idx$ 番目のクエリを処理したときの処理。