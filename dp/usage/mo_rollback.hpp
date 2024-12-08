struct MoRollBack {
  using add_f = function<void(int)>;
  using rem_f = function<void(int)>;
  using rst_f = function<void()>;
  using snap_f = function<void()>;
  using roll_f = function<void()>;

  int bw;           // ブロック幅
  vector<int> l, r; // クエリの範囲 [l, r)
  vector<int> ord;  // クエリの処理順序

  // コンストラクタ
  MoRollBack(int n, int q) 
    : bw(static_cast<int>(sqrt(n))), ord(q) {
    iota(ord.begin(), ord.end(), 0);
  }

  // クエリ追加: 範囲 [a, b) を記録
  void add_query(int a, int b) {
    l.emplace_back(a);
    r.emplace_back(b);
  }

  // Mo's Algorithm の実行
  void run(
    const add_f& add, 
    const rem_f& rem, 
    const rst_f& rst, 
    const snap_f& snap, 
    const roll_f& roll
  ) {
    // クエリの並び替え
    sort(ord.begin(), ord.end(), [&](int a, int b) {
      int ba = l[a] / bw, bb = l[b] / bw;
      if (ba != bb) return ba < bb;
      return r[a] < r[b];
    });

    // 初期化
    rst();

    // 幅が小さいクエリを先に処理
    for (auto i : ord) {
      if (r[i] - l[i] < bw) {
        for (int j = l[i]; j < r[i]; ++j) add(j);
        rem(i);
        roll();
      }
    }

    int cr = 0, lb = -1; // 現在の右端、最後のブロック

    // 幅が大きいクエリを処理
    for (auto i : ord) {
      if (r[i] - l[i] < bw) continue;

      int b = l[i] / bw;
      if (lb != b) {
        rst();
        lb = b;
        cr = (b + 1) * bw;
      }

      while (cr < r[i]) add(cr++);
      snap();
      for (int j = (b + 1) * bw - 1; j >= l[i]; --j) add(j);
      rem(i);
      roll();
    }
  }
};