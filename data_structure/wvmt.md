[top](../README.md)

# [Wavelet Matrix](./wvmt.hpp)

[解説](https://miti-7.hatenablog.com/entry/2019/02/01/152131)

[参考](https://github.com/MitI-7/WaveletMatrix/blob/master/WaveletMatrix/WaveletMatrix.hpp)

全体集合のサイズ $\sigma$ とする。

`wavelet_matrix(vector<ull> a)`

`ull access(ull i)`
- $a_i$ を復元する。
- $O(\log\sigma)$

`ull select(ull c, ull rank)`
- $rank$ 番目の $c$ の位置 $+1$ を返す。 $rank$ は`1-indexed`。
- $O(\log\sigma)$

`ull max_range(ull l, ull r)`
- $[l, r)$ で最大値のindexを返す。

`ull min_range(ull l, ull r)` 

`ull quantile_range(ull l, ull r, ull k)`
- $[l, r)$ で $k$ 番目に小さい数値のindexを返す。 $k$ は`0-indexed`。
- $O(\log\sigma)$

`ull rank(ull c, ull pos)`
- $[0, pos)$ の $c$ の数。
- $O(\log\sigma)$

`ull range_freq(ull l, ull r, ull min, ull max)`
- $[l, r)$ で $[min, max)$ に入る値の個数。
- $O(\log\sigma)$

`ull rank_less_than(ull c, ull l, ull r)`
- $[l, r)$ で $c$ より小さい値の数。
- $O(\log\sigma)$

`ull rank_more_than(ull c, ull l, ull r)`

`tuple<ull, ull, ull> rank_all(ull c, ull l, ull r)`
- $[l, r)$ で $($ $c$ と同じ値の数、$c$ より小さい値の数、$c$ より大きい値の数 $)$ 。
- $O(\log\sigma)$

`pair<ull, ull> topk(ull l, ull r, ull k)`
- $[l, r)$ で出現回数が多い順に $k$ 個の $($ 値, 頻度 $)$ を返す。頻度が同じ場合は小さいものが優先。
- $O(k\log\sigma)$

`ull range_sum(ull l, ull r, ull min, ull max)`
- $[l, r)$ で $[min, max)$ に入る値の総和。
- $O(\log\sigma)$

`ull prev_value(ull l, ull r, ull min, ull max)`
- $[l, r)$ で $[min, max)$ に入る値の最大値
- $O(\log\sigma)$

`ull next_value(ull l, ull r, ull min, ull max)` 
- $[l, r)$ で $[min, max)$ に入る値の最小値。
- $O(\log\sigma)$

`tuple<ull, ull, ull> intersect(ull l1, ull r1, ull l2, ull r2)`
- $[l1, r1)$, $[l2, r2)$ に共通して出現する要素を返す。(tupleの先頭) 
- $O(n)$