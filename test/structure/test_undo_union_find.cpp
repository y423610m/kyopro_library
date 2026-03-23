#include <bits/stdc++.h>
using namespace std;

#include "../../structure/union_find/undo_union_find.hpp"

int main() {
    UndoUnionFind uf(5);
    
    uf.snapshot();
    uf.merge(0, 1);
    uf.merge(1, 2);
    
    assert(uf.same(0, 2));
    assert(uf.size(0) == 3);
    
    uf.undo();
    uf.undo();
    
    assert(!uf.same(0, 1));
    assert(uf.size(0) == 1);
    
    uf.merge(0, 1);
    uf.merge(2, 3);
    uf.snapshot();
    uf.merge(0, 2);
    assert(uf.same(1, 3));
    
    uf.rollback();
    assert(!uf.same(0, 2));
    
    cout << "UndoUnionFind test passed!" << endl;
    return 0;
}
