#include <bits/stdc++.h>
using namespace std;

#include "../../string/rolling_hash.hpp"

int main() {
    RollingHash rh(123456789);
    
    string s = "abcabc";
    auto h = rh.build(s);
    
    assert(rh.query(h, 0, 3) == rh.query(h, 3, 6));
    
    RollingHash rh2;
    string a = "abc";
    string b = "abd";
    auto ha = rh2.build(a);
    auto hb = rh2.build(b);
    
    assert(rh2.lcp(ha, 0, 3, hb, 0, 3) == 2);
    
    auto h1 = rh2.combine(rh2.query(ha, 0, 2), rh2.query(ha, 2, 3), 1);
    assert(h1 == rh2.query(ha, 0, 3));
    
    cout << "RollingHash test passed!" << endl;
    return 0;
}
