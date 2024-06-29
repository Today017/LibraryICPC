#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "./debug.hpp"
#else
#define debug(...)
#define print_line
#endif

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
const int INF = 1e9 + 10;
const ll INFL = 4e18;
#define rep(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define all(x) x.begin(),x.end()

template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

// --------------------------------------------------------

