

// geometry
using Real = long double;
const Real EPS = 1e-8L;
const Real PI = acos(-1.0L);
bool eq(Real a, Real b) {
    return abs(a - b) < EPS;
}

struct point {
    point()=default;
    Real x, y;
    point(Real x, Real y) {
        this->x = x;
        this->y = y;
    }
    point operator+(const point &p) const {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p) const {
        return point(x - p.x, y - p.y);
    }
    point operator*(const Real &d) const {
        return point(x * d, y * d);
    }
    point operator/(const Real &d) const {
        return point(x / d, y / d);
    }
    bool operator==(const point &p) const {
        return eq(x, p.x) && eq(y, p.y);
    }
    bool operator!=(const point &p) const {
        return !(*this == p);
    }
    bool operator<(const point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    Real norm() const {
        return x * x + y * y;
    }
    Real abs() const {
        return sqrt(norm());
    }
    Real arg() const {
        return atan2(y, x);
    }
    Real dot(const point &p) const {
        return x * p.x + y * p.y;
    }
    Real cross(const point &p) const {
        return x * p.y - y * p.x;
    }
    Real dist(const point &p) const {
        return (p - *this).abs();
    }
    point rotate(Real theta) const {
        return point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    }
    point rotate(Real theta, const point &p) const {
        return (p + (*this - p).rotate(theta));
    }
    friend istream &operator>>(istream &is, point &p) {
        return is >> p.x >> p.y;
    }
    friend ostream &operator<<(ostream &os, const point &p) {
        return os << p.x << " " << p.y;
    }
};