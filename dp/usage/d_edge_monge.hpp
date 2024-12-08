#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Incremental Monge shortest path calculation
template <class C, class T = decltype(declval<C>().get())>
T incrementalMongeShortestPath(int n, C init) {
  class Env {
  public:
    C mid, last;
    int prev;
  };
  vector<Env> nodes;
  {
    int d = 0, n_ = n;
    while (n_ != 0) { n_ /= 2; d++; }
    nodes.assign(d, {init, init, 0});
  }
  vector<T> dp(n + 1, static_cast<T>(0));

  const auto f = [&](const auto& f, int d, int r) -> int {
    auto& [mid, last, prev] = nodes[d];
    int w = 1 << d;
    if ((r >> d) % 2 == 1) {
      for (int i = max(0, r - 2 * w); i < r; i++) mid.push_back(i);
      int next = (r + w <= n) ? f(f, d + 1, r + w) : r - w;
      int argmin = prev;
      dp[r] = dp[argmin] + mid.get();
      for (int i = prev; i != next;) {
        mid.pop_front(i);
        i++;
        T t = dp[i] + mid.get();
        if (dp[r] > t) {
          dp[r] = t;
          argmin = i;
        }
      }
      prev = next;
      return argmin;
    } else {
      for (int i = max(0, r - 2 * w); i < r; i++) last.push_back(i);
      for (int i = max(0, r - 3 * w); i < r - 2 * w; i++) last.pop_front(i);
      int argmin = prev;
      for (int i = r - 2 * w; i < r - w;) {
        last.pop_front(i);
        i++;
        T t = dp[i] + last.get();
        if (dp[r] > t) {
          dp[r] = t;
          argmin = i;
        }
      }
      return argmin;
    }
  };

  for (int i = 1; i <= n; i++) f(f, 0, i);

  return dp[n];
}

namespace goldenSectionSearchImpl {
  using i64 = int64_t;

  // Golden Section Search Algorithm
  template <class F, class T = decltype(declval<F>()(declval<i64>())), class Compare = less<T>>
  pair<i64, T> goldenSectionSearch(F f, i64 min, i64 max, Compare comp = Compare()) {
    assert(min <= max);

    i64 a = min - 1, x, b;
    {
      i64 s = 1, t = 2;
      while (t < max - min + 2) swap(s += t, t);
      x = a + t - s;
      b = a + t;
    }
    T fx = f(x), fy;
    while (a + b != 2 * x) {
      const i64 y = a + b - x;
      if (max < y || comp(fx, (fy = f(y)))) {
        b = a;
        a = y;
      } else {
        a = x;
        x = y;
        fx = fy;
      }
    }
    return {x, fx};
  }
}  // namespace goldenSectionSearchImpl

using goldenSectionSearchImpl::goldenSectionSearch;

struct Cost {
  const vector<ll>* a;
  ll lambda;
  ll cost;

  void popFront(int l) {}
  void pushBack(int r) {}
  ll get() { return lambda + cost; }
};

// k : 使用する辺の本数
const auto f = [&](ll l) -> ll {
  return incrementalMongeShortestPath(n + 1, Cost{l, 0, 0}) - l * (k + 1);
};

// L = - max(|e|) * 3, R = max(|e|) * 3
OUT(goldenSectionSearch(f, L, R, greater<ll>()).second);
