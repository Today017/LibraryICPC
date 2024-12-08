template <typename T, typename F>
struct SWAG {
    using vp = vector<pair<T, T>>;
    vp a, b;
    F f;
    T I;
    SWAG(F f, T i) : f(f), I(i) {}

private:
    T get(vp& v) { return empty(v) ? I : v.back().second; }
    void pusha(T x) { a.emplace_back(x, f(x, get(a))); }
    void pushb(T x) { b.emplace_backj(x, f(get(b), x)); }  // reversed!!
    void rebalance() {
        int n = a.size() + b.size();
        int s0 = n / 2 + (empty(a) ? n & 1 : 0);
        vp v{a};
        reverse(v.begin(), v.end());
        copy(b.begin(), b.end(), back_inserter(v));
        a.clear(), b.clear();
        for (int i = s0 - 1; i >= 0; i--) pusha(v[i].first);
        for (int i = s0; i < n; i++) pushb(v[i].first);
    }

public:
    T front() { return (a.empty() ? b.front() : a.back()).first; }
    T back() { return (b.empty() ? a.front() : b.back()).first; }
    void pop_front() {
        if (empty(a)) rebalance();
        a.pop_back();
    }
    void pop_back() {
        if (empty(b)) rebalance();
        b.pop_back();
    }
    T query() { return f(get(a), get(b)); }
};