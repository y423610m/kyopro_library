#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = (1LL<<30)-1;

#include "../../graph/graph_template.hpp"
#include "../../graph/shortest_path/dijkstra.hpp"

int main() {
    int N = 4;
    Graph<int> G(N);
    G.add_edge(0, 1, 1);
    G.add_edge(0, 2, 4);
    G.add_edge(1, 2, 2);
    G.add_edge(1, 3, 6);
    G.add_edge(2, 3, 1);
    
    Dijkstra<int> di(N, INF);
    di.solve(G, 0, 3);
    
    assert(di.dist[0] == 0);
    assert(di.dist[1] == 1);
    assert(di.dist[2] == 3);
    assert(di.dist[3] == 4);
    
    auto path = di.find_path(3);
    assert(path.size() == 4);
    assert(path[0] == 0);
    assert(path[path.size()-1] == 3);
    
    cout << "Dijkstra test passed!" << endl;
    return 0;
}
