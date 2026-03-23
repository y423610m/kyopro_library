#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../../dp/lis.hpp"

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    LIS<vector<int>> lis(a, true);
    
    assert(lis.size() == 3);
    assert(lis.example == vector<int>({1, 2, 3}));
    
    vector<int> b = {3, 1, 2, 4, 3};
    LIS<vector<int>> lis2(b, true);
    
    assert(lis2.size() == 3);
    assert(lis2.example == vector<int>({1, 2, 4}) || lis2.example == vector<int>({1, 2, 3}));
    
    vector<int> c = {1, 1, 1, 1, 1};
    LIS<vector<int>> lis3(c, true);
    assert(lis3.size() == 1);
    
    vector<int> d = {1, 1, 1, 1, 1};
    LIS<vector<int>> lis4(d, false);
    assert(lis4.size() == 5);
    
    cout << "LIS test passed!" << endl;
    return 0;
}
