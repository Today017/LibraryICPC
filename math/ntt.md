[top](../README.md)

# [Numeric Theory Translation](./ntt.hpp)

`vector<mod998> ntt998::convolution(vector<mod998> A, vector<mod998> B)`
- $C = \sum_{k=0}^{n-1} A_k \cdot B_{n-1-k}$ なる $C$ を $\pmod{998244353}$ で計算する。
- $O(n \log n)$ $(n = |A| + |B|)$
