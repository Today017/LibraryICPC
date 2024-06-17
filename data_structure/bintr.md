[top](../README.md)

# [Binary Trie](./bintr.hpp)
だいたいの操作が $O(LOG)$ で可能。

`int size()`
- サイズ取得。

`void insert(T x, int cnt = 1)`
- $x$ を $cnt$ 個挿入する。

`void erase(T x, int cnt = 1)`
- $x$ を $cnt$ 個削除する。

`void apply_xor(T x)`
- 全部の要素に $x$ をxorする。

`T max_element(T bias = 0)`
- 全部の要素に $bias$ をxorした状態で最大要素を取得する。

`T min_element(T bias = 0)`
- 全部の要素に $bias$ をxorした状態で最小要素を取得する。

`T kth_element(int k)`
- $k$ 番目に小さい値を取得する。`0-indexed`。

`int lower_bound(T x)`
- $x$ 以上最小の要素が何番目かを返す。

`int upper_bound(T x)`
- $x$ より大きい最小の要素が何番目かを返す。

`int count(T x)`
- $x$ の個数を返す。