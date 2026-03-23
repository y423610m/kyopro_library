#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../../graph/graph_template.hpp"

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
#else
struct dsu {
    vector<int> p, r;
    dsu(int n): p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool same(int a, int b) { return find(a) == find(b); }
    bool merge(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};
#endif

#include "../../graph/mst/kruskal.hpp"

int main() {
    int N = 4;
    Edges<int> E;
    E.emplace_back(0, 1, 10);
    E.emplace_back(0, 2, 6);
    E.emplace_back(0, 3, 5);
    E.emplace_back(1, 3, 15);
    E.emplace_back(2, 3, 4);
    
    Kruskal<int> krus(N);
    krus.solve(E);
    
    assert(krus.total == 19);
    assert(krus.used.size() == 3);
    
    cout << "Kruskal test passed!" << endl;
    return 0;
}
