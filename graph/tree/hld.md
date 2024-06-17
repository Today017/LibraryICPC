[top](../../README.md)

# [Heavy-Light Decomposition](./hld.hpp)

[解説](https://hcpc-hokudai.github.io/archive/graph_tree_001.pdf)

[使用例](https://atcoder.jp/contests/abc294/submissions/46419196)

`heavy_light_decomposition(int n)`

`heavy_light_decomposition(vector<vector<int>> G)`


`vector<int> start(int root)`
- 頂点 $root$ を根として木を HL 分解する。分解後の木を返す。
- $0\le root < n$
- $O(n)$


`int lca(int u, int v)`
- 頂点 $u$, $v$ の LCA を返す。
- $0\le u, v < n$
- $O(\log{n})$

`void update(int x, U Update)`
- 頂点 $x$ に対して、更新処理 `Update` を適用する。
- $0\le x < n$
- $O(\log{n}f(n))$
- `Update(int x, int pos_x)`
	- 頂点 $x$, HLD後の列における $x$ の位置を $pos_x$ として、列の位置 $pos_x$ に対して更新処理を行う。
	- $O(f(n))$ とする。

`T query(int u, int v, Q Query, F f, T e)`
- パス $u$, $v$ に対して、取得処理 `Query` を適用する。
- $0\le u, v < n$
- $O(\log{n}g(n))$
- `Query(int x, int y)`
	- HLD後の列の区間 $[x, y)$ に対して取得処理を行う。
	- $O(g(n))$ とする。
- `F(T a, T b)`
	- `Query` による取得結果をまとめる演算を行う。 RSQ なら和、 RMQ なら Min/Max 演算を行う。
- `e`
	- 演算 `F` の単位元。

---

#### メンバ
`vector<int> sz`
- 頂点の部分木の大きさ

`vector<int> parent`
- 頂点の親

`vector<int> depth`
- 頂点の深さ

`vector<int> hld`
- HLD結果としての配列

`vector<int> pos`
- `hld`における頂点の位置

`vector<int> head`
- 頂点の属する連結成分の最も浅い頂点