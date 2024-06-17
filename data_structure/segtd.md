[top](../README.md)

# [Segment Tree Dual](./segtd.hpp)

`segment_tree_dual<T>(int n, F f, T e)`
- サイズ $n$ ,演算 $f$, 単位元 $e$ の 双対 Segment Tree を構築する。
- $O(n)$

`void build(vector<T> a)`
- 配列 $a$ から 双対 Segment Tree を構築する。
- $O(n)$

`T operator[](int i)`
- 位置 $i$ の要素を返す。
- $O(\log{n})$

`void apply(int l, int r, T x)`
- 区間 $[l, r)$ に対して $x$ を作用させる。
- $O(\log{n})$

### 区間 add
```cpp
segment_tree_dual<ll> range_add_query(int n) {
    return segment_tree_dual<ll>(n, [](ll a, ll b) { return a + b; }, 0);
}
```

### 区間 update
```cpp
template <typename T>
segment_tree_dual<pair<T, int>> range_update_query(int n) {
    auto f = [](pair<T, int> a, pair<T, int> b) {
        return a.second > b.second ? a : b;
    };
    return segment_tree_dual<pair<T, int>>(n, f, {0, -1});
}
```