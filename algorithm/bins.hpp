template <typename T, typename Judge>
T my_binary_search(T ok, T ng, Judge judge) {
    while (abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        if (judge(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

template <typename T, typename Judge>
T my_binary_search_iteration(T ok, T ng, Judge judge, int count = 100) {
	while (count--) {
        T mid = (ok + ng) / 2;
        if (judge(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}
