#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = (1LL<<30)-1;

#include "../../graph/graph_template.hpp"
#include "../../graph/shortest_path/bellman_ford.hpp"

int main() {
    int N = 4;
    Edges<int> E;
    E.emplace_back(0, 1, 1);
    E.emplace_back(0, 2, 4);
    E.emplace_back(1, 2, 2);
    E.emplace_back(1, 3, 6);
    E.emplace_back(2, 3, 1);
    
    BellmanFord<int> bf(N, INF);
    bf.solve(E, 0, false);
    
    assert(bf.dist[0] == 0);
    assert(bf.dist[1] == 1);
    assert(bf.dist[2] == 3);
    assert(bf.dist[3] == 4);
    
    cout << "BellmanFord test passed!" << endl;
    return 0;
}
