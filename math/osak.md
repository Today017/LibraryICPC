[top](../README.md)

# [Prime Factorization based on Eratosthenes](./osak.hpp)

`factors(int n)`
- $n$ 以下の整数について、高速に素因数分解・約数列挙を行う前計算をする。
- $O(n \log {\log{n}})$

`vector<pair<int, int>> get_prime_factors(int n)`
- $n$ の素因数分解を行う。
- $O(\log n)$

`vector<int> get_divisors(int n)`
- $n$ の約数列挙を行う。
- $O(\log n)$