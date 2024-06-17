[top](../README.md)

# [Numeric Theory Translation](./convolution.hpp)

`vector<double> convolution(vector<double> A, vector<double> B)`
- $C = \sum_{k=0}^{n-1} A_k \cdot B_{n-1-k}$ なる $C$ を計算する。
- $O(n \log n)$ $(n = |A| + |B|)$