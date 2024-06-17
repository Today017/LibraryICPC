#include "../../kyopro_library/template.hpp"

template <typename T = ll>
struct fraction {
    T upper, lower;
    fraction(T a, T b) {
        T g = gcd(a, b);
        upper = a / g;
        lower = b / g;
        if (lower < 0) {
            upper *= -1;
            lower *= -1;
        }
    }
    fraction operator+(const fraction& f) {
        return fraction(upper * f.lower + f.upper * lower, lower * f.lower);
    }
    fraction operator-(const fraction& f) {
        return fraction(upper * f.lower - f.upper * lower, lower * f.lower);
    }
    fraction operator*(const fraction& f) {
        return fraction(upper * f.upper, lower * f.lower);
    }
    fraction operator/(const fraction& f) {
        return fraction(upper * f.lower, lower * f.upper);
    }
    fraction operator+=(const fraction& f) {
        *this = *this + f;
        return *this;
    }
    fraction operator-=(const fraction& f) {
        *this = *this - f;
        return *this;
    }
    fraction operator*=(const fraction& f) {
        *this = *this * f;
        return *this;
    }
    fraction operator/=(const fraction& f) {
        *this = *this / f;
        return *this;
    }
    fraction operator+(const T& f) {
        return fraction(upper + f * lower, lower);
    }
    fraction operator-(const T& f) {
        return fraction(upper - f * lower, lower);
    }
    fraction operator*(const T& f) {
        return fraction(upper * f, lower);
    }
    fraction operator/(const T& f) {
        return fraction(upper, lower * f);
    }
    fraction operator+=(const T& f) {
        *this = *this + f;
        return *this;
    }
    fraction operator-=(const T& f) {
        *this = *this - f;
        return *this;
    }
    fraction operator*=(const T& f) {
        *this = *this * f;
        return *this;
    }
    fraction operator/=(const T& f) {
        *this = *this / f;
        return *this;
    }
    fraction operator-() {
        return fraction(-upper, lower);
    }
    bool operator==(const fraction& f) const {
        return upper == f.upper && lower == f.lower;
    }
    bool operator!=(const fraction& f) const {
        return upper != f.upper || lower != f.lower;
    }
    bool operator<(const fraction& f) const {
        return upper * f.lower < f.upper * lower;
    }
    bool operator<=(const fraction& f) const {
        return upper * f.lower <= f.upper * lower;
    }
    bool operator>(const fraction& f) const {
        return upper * f.lower > f.upper * lower;
    }
    bool operator>=(const fraction& f) const {
        return upper * f.lower >= f.upper * lower;
    }
    bool operator==(const T& f) const {
        return upper == f && lower == 1;
    }
    bool operator!=(const T& f) const {
        return upper != f || lower != 1;
    }
    bool operator<(const T& f) const {
        return upper < f * lower;
    }
    bool operator<=(const T& f) const {
        return upper <= f * lower;
    }
    bool operator>(const T& f) const {
        return upper > f * lower;
    }
    bool operator>=(const T& f) const {
        return upper >= f * lower;
    }
    friend ostream& operator<<(ostream& os, const fraction& f) {
        os << f.upper << "/" << f.lower;
        return os;
    }
};

