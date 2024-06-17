[top](../README.md)

# [Dynamic Li Chao Tree](./dlct.hpp)

`dynamic_li_chao_tree<T, x_low, x_high, id>()`
- $x$ の範囲が $x_{low} \le x \le x_{high}$ 要素の最大値が $id$ であるような Dynamic Li Chao Tree を構築する。

`void add_line(T a, T b)`
- 直線 $y=ax+b$ を追加する。
- $O(\log{n})$

`void add_segment(T l, T r, T a, T b)`
- 区間 $[l,r)$ に直線 $y=ax+b$ を追加する。
- $O(\log^2{n})$

`void query(T x)`
- $ax+b$ の**最小値**を求める。