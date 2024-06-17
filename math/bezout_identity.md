[top](../README.md)

# [Bezout Identity](./bezout_identity.hpp)

`bezout_identity(ll a, ll b, ll c)`
- 不定一次方程式 $ax + by = c$ を解く。

`bool build()`
- 解を構築する。解が無い場合 `false` を返す。

`pair<ll, ll> general_solution(ll t)`
- $t$ に特徴づけられる解 $(x, y)$ を返す。

### 解説

$g=\gcd(a,b)$ とする。
`extgcd` によって、 $ax' + by' = g$ を解く。

辺々を $\frac{c}{g}$ 倍し、 $x=x'\times\frac{c}{g}, y=y'\times\frac{c}{g}$ とすると、
これらは元の方程式 $ax + by = c$ を満たしている。

$c$ が $g$ で割り切れない場合、解は存在しない。

$ax + by = c$ の辺々を $g$ で割ると $\frac{a}{g}x + \frac{b}{g}y = \frac{c}{g}$ である。方程式の一般解を $X,Y$ とおくと、
$\frac{a}{g}(X-x) + \frac{b}{g}(Y-y) = 0$ を満たす。 $\frac{a}{g}$ と $\frac{b}{g}$ は互いに素であるので $X-x$ は $\frac{b}{g}$ の倍数であり、
$X=\frac{b}{g}\times t +x$ となる。

これを再代入して $Y=\frac{-a}{g}\times t +y$ である。

---

オーバーフローが怖いときはこっち。

```python
class BezoutIdentity:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
        self.g = None
        self.X = None
        self.Y = None

    def extgcd(self, a, b):
        if b == 0:
            return (a, 1, 0)
        q = a // b
        r = a % b
        g, s, t = self.extgcd(b, r)
        x = t
        y = s - q * t
        return (g, x, y)

    def build(self):
        g, X, Y = self.extgcd(abs(self.a), abs(self.b))
        if self.c % g != 0:
            return False
        self.g = g
        self.X = X
        self.Y = Y
        if self.a < 0:
            self.X = -self.X
        if self.b < 0:
            self.Y = -self.Y
        self.X *= self.c // g
        self.Y *= self.c // g
        return True

    def general_solution(self, t=0):
        x = self.b // self.g * t + self.X
        y = -self.a // self.g * t + self.Y
        return (x, y)
```
