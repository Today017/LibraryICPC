template <typename T>
struct my_set : set<T> {
    using set<T>::set;
    T not_found = -1;
    my_set() = default;
    my_set(T not_found) {
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
    T le(T x) {
        auto itr = this->upper_bound(x);
        if (itr == this->begin()) {
            return not_found;
        }
        return *prev(itr);
    }
    T lt(T x) {
        auto itr = this->lower_bound(x);
        if (itr == this->begin()) {
            return not_found;
        }
        return *prev(itr);
    }
};
