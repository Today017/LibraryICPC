#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// x_i = floor((a*i+b)/m), i = 0, 1, ..., n-1
// a, c > 0, b >= 0
ll FloorSum(ll n, ll a, ll b, ll c) {
    if (n == 0) return 0;
    ll ret = n * (n-1) / 2 * (a/c);
    a %= c;
    ret += n * (b/c);
    b %= c;
    if (a == 0) return ret;
    ll top = (a * (n-1) + b) / c;
    ret += top * n;
    ll h = (b+c) / c;
    if (h <= top) ret -= FloorSum(top-h+1, c, c*h-b-1, a) + (top-h+1);
    return ret;
}