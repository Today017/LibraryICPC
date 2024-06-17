#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
struct sorted_tree : tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {
    using tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>::tree;
    T not_found = -1;
    sorted_tree() = default;
    sorted_tree(T not_found) {
        this->not_found = not_found;
    }
    T min() {
        if (this->empty()) {
            return not_found;
        }
        return *this->begin();
    }
    T max() {
        if (this->empty()) {
            return not_found;
        }
        return *this->rbegin();
    }
    T pop_min() {
        if (this->empty()) {
            return not_found;
        }
        T ret = min();
        this->erase(ret);
        return ret;
    }
    T pop_max() {
        if (this->empty()) {
            return not_found;
        }
        T ret = max();
        this->erase(ret);
        return ret;
    }
    bool contains(T x) {
        return this->find(x) != this->end();
    }
    bool discard(T x) {
        auto itr = this->find(x);
        if (itr == this->end()) {
            return false;
        }
        this->erase(itr);
        return true;
    }
    T gt(T x) {
        auto itr = this->upper_bound(x);
        if (itr == this->end()) {
            return not_found;
        }
        return *itr;
    }
    T ge(T x) {
        auto itr = this->lower_bound(x);
        if (itr == this->end()) {
            return not_found;
        }
        return *itr;
    }
    T lt(T x) {
        auto itr = this->lower_bound(x);
        if (itr == this->begin()) {
            return not_found;
        }
        return *--itr;
    }
    T le(T x) {
        auto itr = this->upper_bound(x);
        if (itr == this->begin()) {
            return not_found;
        }
        return *--itr;
    }
    int count_lt(T x) {
        return this->order_of_key(x);
    }
    int count_le(T x) {
        return this->order_of_key(x + 1);
    }
    int count_gt(T x) {
        return this->size() - this->order_of_key(x + 1);
    }
    int count_ge(T x) {
        return this->size() - this->order_of_key(x);
    }
    T kth_min(int k) {
        return *this->find_by_order(k);
    }
    T kth_max(int k) {
        return *this->find_by_order(this->size() - k - 1);
    }
};
