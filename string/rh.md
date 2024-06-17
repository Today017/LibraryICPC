[top](../README.md)

# [Rolling Hash](./rh.hpp)

`rolling_hash(string s, vector<ll> base)`
- 文字列 $s$ から $base$ を基数とした Rolling Hash を構築する。
- `base` に引数を渡さない場合、ランダムに選択される。複数の文字列の Rolling Hash を別々に構築して後で比較を行う場合は、 `base` を揃えるように注意すること。
- $O(n)$

`hash get(int l, int r)`
- 区間 $[l, r)$ のハッシュ値を返す。
- $O(1)$

`hash connect(hash h1, hash h2, int len1)`
- 長さが $len_1$, ハッシュ値が $h1$ であるような文字列と、ハッシュ値が $h2$ であるような文字列を連結した文字列のハッシュ値を返す。
- $O(1)$