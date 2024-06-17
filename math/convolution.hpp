#include "../../kyopro_library/template.hpp"

vector<complex<double>> fft(vector<complex<double>> a, bool inv = false) {
    int n = a.size();
    int h = 0;
    while ((1 << h) < n) {
        h++;
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        // ビットを逆に
        for (int k = 0; k < h; k++) {
            j |= (i >> k & 1) << (h - 1 - k);
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int b = 1; b < n; b <<= 1) {
        for (int j = 0; j < b; j++) {
            // b=ブロックサイズの半分
            // j,j+bを計算
            // w=exp(-2pij/2b)=1のb乗根のj乗
            complex<double> w = polar(1.0, (2.0 * M_PI) / (2.0 * b) * j * (inv ? 1 : -1));
            // ブロックサイズ2bだけずらしながら計算
            for (int k = 0; k < n; k += b * 2) {
                complex<double> s = a[j + k];
                complex<double> t = a[j + k + b] * w;
                a[j + k] = s + t;
                a[j + k + b] = s - t;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
    return a;
}

vector<double> convolution(vector<double> a, vector<double> b) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size() - 1) {
        n <<= 1;
    }
    vector<complex<double>> fa(n), fb(n);
    for (int i = 0; i < (int)a.size(); i++) {
        fa[i] = a[i];
    }
    for (int i = 0; i < (int)b.size(); i++) {
        fb[i] = b[i];
    }
    fa = fft(fa);
    fb = fft(fb);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fa = fft(fa, true);
    vector<double> ret(n);
    for (int i = 0; i < n; i++) {
        ret[i] = fa[i].real();
    }
    while ((int)ret.size() > (int)a.size() + (int)b.size() - 1) {
        ret.pop_back();
    }
    return ret;
}