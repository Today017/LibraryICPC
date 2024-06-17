template <typename T>
struct dynamic_li_chao_tree {
    dynamic_li_chao_tree(T x_low, T x_high, T id) {
        this->root = nullptr;
        this->x_low = x_low;
        this->x_high = x_high;
        this->id = id;
    }
    void add_line(const T &a, const T &b) {
        line x(a, b);
        this->root = add_line(this->root, x, x_low, x_high, x.get(x_low), x.get(x_high));
    }
    void add_segment(const T &l, const T &r, const T &a, const T &b) {
        line x(a, b);
        this->root = add_segment(this->root, x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));
    }
    T query(const T &x) const {
        return query(this->root, x_low, x_high, x);
    }

private:
    struct line {
        T a, b;
        line(T a, T b) : a(a), b(b) {}
        inline T get(T x) const { return a * x + b; }
    };
    struct node {
        line x;
        node *l, *r;
        node(const line &x) : x{x}, l{nullptr}, r{nullptr} {}
    };
    node *root;
    T x_low, x_high, id;
    node *add_line(node *t, line &x, const T &l, const T &r, const T &x_l, const T &x_r) {
        if (!t) return new node(x);
        T t_l = t->x.get(l), t_r = t->x.get(r);
        if (t_l <= x_l && t_r <= x_r) {
            return t;
        } else if (t_l >= x_l && t_r >= x_r) {
            t->x = x;
            return t;
        } else {
            T m = (l + r) / 2;
            if (m == r) --m;
            T t_m = t->x.get(m), x_m = x.get(m);
            if (t_m > x_m) {
                swap(t->x, x);
                if (x_l >= t_l) {
                    t->l = add_line(t->l, x, l, m, t_l, t_m);
                } else {
                    t->r = add_line(t->r, x, m + 1, r, t_m + x.a, t_r);
                }
            } else {
                if (t_l >= x_l) {
                    t->l = add_line(t->l, x, l, m, x_l, x_m);
                } else {
                    t->r = add_line(t->r, x, m + 1, r, x_m + x.a, x_r);
                }
            }
            return t;
        }
    }
    node *add_segment(node *t, line &x, const T &a, const T &b, const T &l, const T &r, const T &x_l, const T &x_r) {
        if (r < a || b < l) return t;
        if (a <= l && r <= b) {
            line y{x};
            return add_line(t, y, l, r, x_l, x_r);
        }
        if (t) {
            T t_l = t->x.get(l), t_r = t->x.get(r);
            if (t_l <= x_l && t_r <= x_r) return t;
        } else {
            t = new node(line(0, id));
        }
        T m = (l + r) / 2;
        if (m == r) --m;
        T x_m = x.get(m);
        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);
        t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);
        return t;
    }
    T query(const node *t, const T &l, const T &r, const T &x) const {
        if (!t) return id;
        if (l == r) return t->x.get(x);
        T m = (l + r) / 2;
        if (m == r) --m;
        if (x <= m) {
            return min(t->x.get(x), query(t->l, l, m, x));
        } else {
            return min(t->x.get(x), query(t->r, m + 1, r, x));
        }
    }
};
