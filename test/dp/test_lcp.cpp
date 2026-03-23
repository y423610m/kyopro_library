#include <bits/stdc++.h>
using namespace std;

#include "../../dp/lcp.hpp"

int main() {
    string S = "abc";
    string T = "abdabc";
    
    LCP lcp(S, T);
    
    assert(lcp[0][0] == 2);
    assert(lcp[0][1] == 0);
    assert(lcp[1][0] == 0);
    assert(lcp[2][2] == 0);
    
    string A = "abc";
    string B = "abc";
    LCP lcp2(A, B);
    assert(lcp2[0][0] == 3);
    
    cout << "LCP test passed!" << endl;
    return 0;
}
