#include <bits/stdc++.h>
using namespace std;

#include "../../others/my_hash.hpp"

int main() {
    MyHashGenerator<long long> gen(100);
    
    MyHash h1 = gen.get(123);
    MyHash h2 = gen.get(123);
    MyHash h3 = gen.get(456);
    
    assert(h1 == h2);
    assert(!(h1 == h3));
    assert((h1 ^ h3) == (h1 ^ h3));
    
    cout << "MyHash test passed!" << endl;
    return 0;
}
