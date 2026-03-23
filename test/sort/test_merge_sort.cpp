#include <bits/stdc++.h>
using namespace std;

#include "../../sort/merge_sort.hpp"

int main() {
    vector<int> a = {5, 3, 4, 1, 2};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    merge_sort(a.begin(), a.end());
    
    assert(a == expected);
    
    vector<int> b = {1};
    merge_sort(b.begin(), b.end());
    assert(b == vector<int>({1}));
    
    vector<int> c;
    merge_sort(c.begin(), c.end());
    assert(c.empty());
    
    vector<int> d = {2, 1, 3, 1, 2};
    merge_sort(d.begin(), d.end());
    assert(d == vector<int>({1, 1, 2, 2, 3}));
    
    cout << "MergeSort test passed!" << endl;
    return 0;
}
