#include <bits/stdc++.h>
using namespace std;

int op(const int& a, const int& b) {
    return max(a, b);
}

#include "../../structure/others/sparse_table.hpp"

int main() {
    vector<int> v = {1, 3, 2, 5, 4, 1, 2, 8};
    SparseTable<int, decltype(&op)> st(v, op);
    
    assert(st.fold(0, 4) == 5);
    assert(st.fold(2, 6) == 5);
    assert(st.fold(0, 8) == 8);
    assert(st.fold(0, 1) == 1);
    assert(st.fold(6, 8) == 8);
    
    auto st2 = get_sparse_table(v, [](int a, int b){ return min(a, b); });
    assert(st2.fold(0, 4) == 1);
    assert(st2.fold(2, 6) == 1);
    
    cout << "SparseTable test passed!" << endl;
    return 0;
}
