#include "../../kyopro_library/template.hpp"

struct trie {
    struct node {
        array<int, 26> to;
        int count_of_end = 0, count_of_node = 0;
        node() {
            fill(to.begin(), to.end(), -1);
        }
    };
    trie(int len) {
        nodes.reserve(len);
        node root;
        nodes.push_back(root);
    }
    void insert(const string &s) {
        int cur = 0;
        for (const char &c : s) {
            int &nxt = nodes[cur].to[c-'a'];
            if (nxt == -1) {
                nxt = nodes.size();
                nodes.push_back(node());
            }
            cur = nxt;
            nodes[cur].count_of_node++;
        }
        nodes[cur].count_of_end++;
    }
    int count(const string &s) {
        int cur = 0;
        int ret = 0;
        for (const char &c : s) {
            int &nxt = nodes[cur].to[c-'a'];
            if (nxt == -1) {
                return 0;
            }
            cur = nxt;
            ret = nodes[cur].count_of_end;
        }
    }
    void erase(const string &s) {
        int cur = 0;
        for (const char &c : s) {
            int &nxt = nodes[cur].to[c-'a'];
            if (nxt == -1) {
                return;
            }
            cur = nxt;
            nodes[cur].count_of_node--;
        }
        nodes[cur].count_of_end--;
    }

private:
    vector<node> nodes;
};