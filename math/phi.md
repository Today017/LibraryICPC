[top](../README.md)

# [Euler's Phi Function](./phi.hpp)

`ll euler_phi(ll n)`
- $n$ 以下の自然数であって $n$ と互いに素なものの個数を返す。
- $O(\sqrt{n})$

`ll euler_phi2(ll n)`
- 約数包除解法。

`vector<ll> euler_phi_table(ll n)`
- $n$ 以下の自然数に対する $\phi$ 関数の値のテーブルを返す。
- $O(n \log n)$
