[top](../README.md)

# [Segment Tree](./segt.hpp)

`segment_tree<T>(int n, F f, T e)`
- サイズ $n$ ,演算 $f$, 単位元 $e$ の Segment Tree を構築する。
- 集合 $T$, 演算 $f$, 単位元 $e$ が単位半群を為すことを要求する。
- $O(n)$

`void build(vector<T> a)`
- 配列 $a$ から Segment Tree を構築する。
- $O(n)$

`void set(int i, T x)`
- 位置 $i$ の要素を $x$ に変える。
- $O(\log{n})$

`T query(int l, int r)`
- 区間 $[l, r)$ に対しての演算結果を返す。
- $O(\log{n})$

`T operator[int i]`
- 位置 $i$ の要素を返す。
- $O(1)$

`int size()`
- Segment Tree のサイズを返す。
- $O(1)$

### 区間 min
```cpp
template <typename T>
segment_tree<T> range_min_query(int n, T e = numeric_limits<T>::max()) {
    auto f = [](T a, T b) {
        return min(a, b);
    };
    return segment_tree<T>(n, f, e);
}
```

### 区間 max
```cpp
template <typename T>
segment_tree<T> range_max_query(int n, T e = numeric_limits<T>::min()) {
    auto f = [](T a, T b) {
        return max(a, b);
    };
    return segment_tree<T>(n, f, e);
}
```

### 区間和
```cpp
template <typename T>
segment_tree<T> range_sum_query(int n, T e = 0) {
    auto f = [](T a, T b) {
        return a + b;
    };
    return segment_tree<T>(n, f, e);
}
```