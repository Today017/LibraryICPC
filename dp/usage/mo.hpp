struct Mo {
  int n;                  // 配列サイズ
  vector<pair<int, int>> lr; // クエリの範囲 [l, r)

  // コンストラクタ
  Mo(int n) : n(n) {}

  // クエリ追加: 範囲 [l, r) を記録
  void add_query(int l, int r) {
    lr.emplace_back(l, r);
  }

  // Mo's Algorithm の実行
  template <typename add_l, typename add_r, typename erase_l, typename erase_r, typename output>
  void build(const add_l& al, const add_r& ar, const erase_l& el, const erase_r& er, const output& out) {
    int q = lr.size();
    int block_size = n / max<int>(1, sqrt(q)); // ブロックサイズ計算
    vector<int> ord(q); // クエリ順序
    iota(ord.begin(), ord.end(), 0);

    // クエリの並び替え
    sort(ord.begin(), ord.end(), [&](int a, int b) {
      int ba = lr[a].first / block_size, bb = lr[b].first / block_size;
      if (ba != bb) return ba < bb;
      return (ba & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
    });

    int l = 0, r = 0;

    // 各クエリを処理
    for (auto i : ord) {
      while (l > lr[i].first) al(--l);   // 左端を拡張
      while (r < lr[i].second) ar(r++); // 右端を拡張
      while (l < lr[i].first) el(l++);  // 左端を縮小
      while (r > lr[i].second) er(--r); // 右端を縮小
      out(i);                           // 結果を出力
    }
  }

  // add, erase が同一の場合の簡略版
  template <typename add_erase, typename output>
  void build(const add_erase& ae, const add_erase& e, const output& out) {
    build(ae, ae, e, e, out);
  }
};