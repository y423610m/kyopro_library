#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../../math/combnination.hpp"

int main() {
    Combination<int> comb(100);
    
    assert(comb.fact(5) == 120);
    assert(comb.fact(10) == 3628800);
    
    cout << "Combination test passed!" << endl;
    return 0;
}
