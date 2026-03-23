#include <bits/stdc++.h>
using namespace std;

#include "../../sort/bubble_sort.hpp"

int main() {
    vector<int> a = {5, 3, 4, 1, 2};
    vector<int> expected = {1, 2, 3, 4, 5};
    
    bubble_sort(a.begin(), a.end());
    
    assert(a == expected);
    
    vector<int> b = {1};
    bubble_sort(b.begin(), b.end());
    assert(b == vector<int>({1}));
    
    vector<int> c;
    bubble_sort(c.begin(), c.end());
    assert(c.empty());
    
    cout << "BubbleSort test passed!" << endl;
    return 0;
}
