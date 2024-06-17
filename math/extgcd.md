[top](../README.md)

# [ExtGCD, Mod Inversion](./extgcd.hpp)

[解説](https://maspypy.com/%E6%95%B0%E5%AD%A6%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0-euclid%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95)

`tuple<ll, ll, ll> extgcd(ll a, ll b)`
- $ax + by = \gcd(a, b)$ なる $x$, $y$ を計算する。
- $\gcd(a, b), x, y$ の組を返す。
- $O(\log{\min(a, b)})$

`ll modinv(ll a, ll m)`
- $ax\equiv 1 \mod m$ なる $x$ を返す。
- $\gcd(a, m) = 1$ でない場合、 $-1$ を返す。

### 解説
$ax\equiv 1 \mod m \leftrightarrow ax + my \equiv 1 \mod m$ より、 `extgcd` を用いて求めることができる。