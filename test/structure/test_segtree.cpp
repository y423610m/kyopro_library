#include <bits/stdc++.h>
using namespace std;

struct SegOp {
    using S = int;
    static S op(S a, S b) { return max(a, b); }
    static S e() { return INT_MIN; }
};

#include "../../structure/segtree/segtree.hpp"

int main() {
    vector<int> a = {1, 3, 2, 5, 4};
    SegmentTree<int, SegOp::op, SegOp::e> seg(5);
    
    for(int i = 0; i < 5; i++) seg.Set(i, a[i]);
    
    assert(seg.Get(0) == 1);
    assert(seg.Get(2) == 2);
    
    assert(seg.Product(0, 3) == 3);
    assert(seg.Product(0, 5) == 5);
    assert(seg.Product(2, 4) == 5);
    
    seg.Set(4, 10);
    assert(seg.Product(0, 5) == 10);
    
    cout << "SegmentTree test passed!" << endl;
    return 0;
}
