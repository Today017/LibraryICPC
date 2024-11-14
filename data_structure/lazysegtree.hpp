template <typename T,
            T (*op)(T, T),
            T (*e)(),
            typename U,
            T (*mp)(U, T),
            U (*cp)(U, U),
            U (*id)()>
struct LazySegtree {
};