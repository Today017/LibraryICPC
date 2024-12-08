#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using PQ = priority_queue<T, greater<T>, rc_binomial_heap_tag>;
using Trie = trie<string,
                  null_type,
                  trie_string_access_traits<>,
                  pat_trie_tag,
                  trie_prefix_search_node_update>;
// not a multiset
// find_by_order(k) -> itr of k-th(0-based) element
// order_of_key(k) -> index of lower_bound(k)
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

#include <ext/rope>
using namespace __gnu_cxx;