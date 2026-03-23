#include <bits/stdc++.h>
using namespace std;

#include "../../structure/union_find/union_find.hpp"

int main() {
    UnionFind uf(5);
    
    assert(uf.leader(0) == 0);
    assert(uf.size(0) == 1);
    assert(!uf.same(0, 1));
    
    uf.merge(0, 1);
    assert(uf.same(0, 1));
    assert(uf.size(0) == 2);
    
    uf.merge(2, 3);
    uf.merge(0, 2);
    assert(uf.same(1, 3));
    assert(uf.size(0) == 4);
    
    auto groups = uf.groups();
    assert(groups.size() == 2);
    
    cout << "UnionFind test passed!" << endl;
    return 0;
}
