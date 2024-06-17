#include "../../kyopro_library/template.hpp"

template <typename T>
using matrix = vector<vector<T>>;
template <typename T>
matrix<T> operator*(const matrix<T>& a, const matrix<T>& b) {
    int n = a.size();
    matrix<T> ret(n, vector<T>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}
template <typename T>
matrix<T> operator^(matrix<T> a, ll b) {
    int n = a.size();
    matrix<T> ret(n, vector<T>(n));
    for (int i = 0; i < n; i++) {
        ret[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            ret = ret * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ret;
}
