#include <bits/stdc++.h>
using namespace std;

#include "../../structure/tree/implicit_treap.hpp"

int main() {
    SumAddQuery<long long, long long> treap;
    vector<long long> a = {1, 2, 3, 4, 5};
    treap.set_by_vector(a);
    
    assert(treap.size() == 5);
    assert(treap.query(0, 3) == 6);
    assert(treap[2] == 3);
    
    treap.insert(2, 10);
    assert(treap.size() == 6);
    assert(treap[2] == 10);
    
    treap.update(1, 4, 5);
    assert(treap.query(0, 6) == 40);
    
    treap.erase(2);
    assert(treap.size() == 5);
    
    MinAddQuery<int, int> minTreap;
    vector<int> b = {5, 3, 4, 1, 2};
    minTreap.set_by_vector(b);
    
    assert(minTreap.query(0, 5) == 1);
    
    minTreap.reverse(0, 3);
    assert(minTreap[0] == 4);
    assert(minTreap[2] == 5);
    
    cout << "ImplicitTreap test passed!" << endl;
    return 0;
}
