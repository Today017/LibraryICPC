[top](../README.md)

# [Random Generator](./random.hpp)

`namespace random_generator`
- ランダムテストケース生成用ツール。

`void init()`
- シード値を設定する。

`T randint(T x)`
- $[0, x)$ の範囲でランダムな整数を生成する。

`T randint(T l, T r)`
- $[l, r)$ の範囲でランダムな整数を生成する。

`T get_element(vector<T> a)`
- $a$ の中でランダムな要素を取得し、削除する。

`vector<T> random_array_int(int n, int lo, int hi, bool no_dup)`
- 長さ $n$, 範囲 $[l, r)$ のランダムな数列を生成する。
- `no_dup` を `true` とすると、重複のない数列となる。

`string random_alphabet(int n, bool lower = true)`
- 長さ $n$ のアルファベットからなるランダムな文字列を生成する。
- `lower` を `false` とすると uppercase のみからなる文字列となる。

`string random_string(int n, string s)`
- 長さ $n$, 文字列 $s$ の要素からなるランダムな文字列を生成する。

`vector<vector<T>> random_array_2D(int h, int w, T lo, T hi)`
- 縦、横の長さ $h$, $w$, 範囲 $[lo, hi)$ のランダムな 2 次元の数列を生成する。

`vector<string> random_alphabet_2D(int h, int w, bool lower)`
- 縦、横の長さ $h$, $w$, のランダムな文字列列を生成する。
- `lower` を `false` とすると uppercase のみからなる文字列となる。

`vector<pair<int, int>> random_tree(int n)`
- 頂点数 $n$ の木を生成する。`1-indexed` 。

`vector<pair<int, int>> random_bintree(int n)`
- 頂点数 $n$ の完全二分木を生成する。`1-indexed` 。

`vector<pair<int, int>> random_undigraph(int n, int m, bool connected)`
- 頂点数 $n$, 辺数 $m$ の無向グラフを生成する。`connected` を `false` とすると連結とは限らないグラフを生成する。

---

```cpp
#pragma once
#include "../../kyopro_library/template.hpp"

namespace random_generator {
    mt19937_64 generate;
    void init() {
        random_device seed_gen;
        generate = mt19937_64(seed_gen());
    }
    template <typename T>
    T random_int(T x) {
        assert(x > 0);
        return generate() % x;
    }
    template <typename T>
    T random_int(T x, T y) {
        assert(x < y);
        return x + generate() % (y - x);
    }
    template <typename T>
    T get_elememt(vector<T>& a) {
        const int n = a.size();
        int idx = random_int(0, n);
        swap(a[n - 1], a[idx]);
        int ret = a.back();
        a.pop_back();
        return ret;
    }
    template <typename T>
    vector<T> random_array_int(int n, T lo, T hi, bool no_dup = false) {
        vector<T> ret(n);
        if (!no_dup) {
            for (int i = 0; i < n; i++) {
                ret[i] = random_int(lo, hi);
            }
        } else {
            set<T> st;
            for (int i = 0; i < n; i++) {
                int r = random_int(lo, hi);
                while (st.count(r)) {
                    r = random_int(lo, hi);
                }
                ret[i] = r;
                st.insert(r);
            }
        }
        return ret;
    }
    string random_alphabet(int n, bool lower = true) {
        string ret;
        for (int i = 0; i < n; i++) {
            int idx = random_int(26);
            ret.push_back(char((lower ? 'a' : 'A') + idx));
        }
        return ret;
    }
    string random_string(int n, string s) {
        string ret;
        int m = s.size();
        for (int i = 0; i < n; i++) {
            int idx = random_int(m);
            ret.push_back(s[idx]);
        }
        return ret;
    }
    template <typename T>
    vector<vector<T>> random_array_2D(int h, int w, T lo, T hi) {
        vector<vector<T>> ret(h, vector<T>(w));
        for (int i = 0; i < h; i++) {
            ret[i] = random_array_int(w, lo, hi);
        }
        return ret;
    }
    vector<string> random_alphabet_2D(int h, int w, bool lower = true) {
        vector<string> ret(h);
        for (int i = 0; i < h; i++) {
            ret[i] = random_alphabet(w, lower);
        }
        return ret;
    }
    vector<pair<int, int>> random_tree(int n) {
        vector<int> a = random_array_int<int>(n - 2, 1, n + 1);
        vector<int> d(n + 1);
        for (int i = 0; i < n - 2; i++) {
            d[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            d[i]++;
        }
        vector<pair<int, int>> ret;
        set<int> pq;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 1) {
                pq.insert(i);
            }
        }
        for (int i = 0; i < n - 2; i++) {
            int v = (*pq.begin());
            pq.erase(v);
            ret.push_back(make_pair(v, a[i]));
            d[v]--;
            d[a[i]]--;
            if (d[a[i]] == 1) {
                pq.insert(a[i]);
            } else if (d[a[i]] == 0) {
                pq.erase(a[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] == 1) {
                for (int j = i + 1; j <= n; j++) {
                    if (d[j] == 1) {
                        ret.push_back(make_pair(i, j));
                        break;
                    }
                }
                break;
            }
        }
        return ret;
    }
    vector<pair<int, int>> random_bintree(int n) {
        vector<pair<int, int>> ret;
        vector<ll> roots = {random_int(1, n + 1)};
        vector<ll> leaves;
        for (int i = 1; i <= n; i++) {
            if (i != roots.back()) {
                leaves.push_back(i);
            }
        }
        while (!leaves.empty()) {
            int root = get_elememt(roots);
            int leaf = get_elememt(leaves);
            ret.push_back(make_pair(root, leaf));
            roots.push_back(leaf);
            if (!leaves.empty()) {
                int leaf = get_elememt(leaves);
                ret.push_back(make_pair(root, leaf));
                roots.push_back(leaf);
            }
        }
        return ret;
    }
    vector<pair<int, int>> random_undigraph(int n, int m, bool connected = true) {
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.push_back(make_pair(i + 1, j + 1));
            }
        }
        int ed = edges.size();
        if (!connected) {
            vector<pair<int, int>> ret;
            vector<int> idxs = random_array_int<int>(m, 0, ed, true);
            for (int idx : idxs) {
                ret.push_back(edges[idx]);
            }
            return ret;
        } else {
            vector<pair<int, int>> ret;
            while (true) {
                ret.clear();
                vector<int> idxs = random_array_int<int>(m, 0, ed, true);
                vector<int> parent(n);
                vector<vector<int>> sets(n);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                    sets[i].push_back(i);
                }
                for (int idx : idxs) {
                    ret.push_back(edges[idx]);
                    auto [a, b] = edges[idx];
                    a--;
                    b--;
                    if (parent[a] != parent[b]) {
                        if (sets[parent[a]].size() < sets[parent[b]].size()) {
                            swap(a, b);
                        }
                        for (int x : sets[parent[b]]) {
                            parent[x] = parent[a];
                            sets[parent[a]].push_back(x);
                        }
                        sets[parent[b]].clear();
                    }
                }
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    if (parent[i] != parent[0]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return ret;
                }
            }
        }
    }
};  // namespace random_generator

struct setup_random {
    setup_random() {
        random_generator::init();
    }
} setup_random_instance;
```