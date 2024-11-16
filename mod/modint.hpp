using ull = unsigned long long;
template <ull mod>
struct mint {
    ull x;
    mint(const ull x = 0) : x(x % mod) {}
    mint operator-() const { return mint(mod - x); }
    mint operator+(const mint &y) const { return mint(*this) += y; }
    mint operator-(const mint &y) const { return mint(*this) -= y; }
    mint operator*(const mint &y) const { return mint(*this) *= y; }
    mint operator/(const mint &y) const { return mint(*this) /= y; }
    mint &operator+=(const mint &y) {
        x += y.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint &operator-=(const mint &y) {
        if (x < y.x) x += mod;
        x -= y.x;
        return *this;
    }
    mint &operator*=(const mint &y) {
        x = x * y.x % mod;
        return *this;
    }
    mint &operator/=(const mint &y) {
        x = x * y.inv().x % mod;
        return *this;
    }
    mint pow(ull n) const {
        mint r(1), m(x);
        while (n) {
            if (n & 1) r *= m;
            m *= m;
            n >>= 1;
        }
        return r;
    }
    mint inv() const { return pow(mod - 2); }
};