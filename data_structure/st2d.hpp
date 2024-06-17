struct {
    int h, w;
    ll sign;
    ll dat[12][12][1010][1010];
    ll log_table[5050];
} sparse_table_2D;

void sparse_table_2D_init(const vector<vector<ll>>& a, bool is_min = true) {
    if (!is_min) {
        sparse_table_2D.sign = -1;
    }
    sparse_table_2D.h = a.size();
    sparse_table_2D.w = a[0].size();
    for (int i = 0; i < sparse_table_2D.h; i++) {
        for (int j = 0; j < sparse_table_2D.w; j++) {
            sparse_table_2D.dat[0][0][i][j] = sparse_table_2D.sign * a[i][j];
        }
    }
    for (int i = 2; i <= max(sparse_table_2D.h, sparse_table_2D.w); i++) {
        sparse_table_2D.log_table[i] = sparse_table_2D.log_table[i / 2] + 1;
    }
    for (int k = 1; (1 << k) <= sparse_table_2D.h; k++) {
        for (int i = 0; i + (1 << k) <= sparse_table_2D.h; i++) {
            for (int j = 0; j < sparse_table_2D.w; j++) {
                sparse_table_2D.dat[k][0][i][j] = min(sparse_table_2D.dat[k - 1][0][i][j], sparse_table_2D.dat[k - 1][0][i + (1 << (k - 1))][j]);
            }
        }
    }
    for (int k = 0; (1 << k) <= sparse_table_2D.h; k++) {
        for (int l = 1; (1 << l) <= sparse_table_2D.w; l++) {
            for (int i = 0; i + (1 << k) <= sparse_table_2D.h; i++) {
                for (int j = 0; j + (1 << l) <= sparse_table_2D.w; j++) {
                    sparse_table_2D.dat[k][l][i][j] = min(sparse_table_2D.dat[k][l - 1][i][j], sparse_table_2D.dat[k][l - 1][i][j + (1 << (l - 1))]);
                }
            }
        }
    }
}

ll sparse_table_2D_query(int l, int r, int u, int d) {
    int i = sparse_table_2D.log_table[r - l];
    int j = sparse_table_2D.log_table[d - u];
    return min({sparse_table_2D.dat[i][j][l][u], sparse_table_2D.dat[i][j][r - (1 << i)][u], sparse_table_2D.dat[i][j][l][d - (1 << j)], sparse_table_2D.dat[i][j][r - (1 << i)][d - (1 << j)]}) * sparse_table_2D.sign;
}
