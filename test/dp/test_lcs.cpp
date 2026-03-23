#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define chmax(a,b) (a=max(a,b))

#include "../../dp/lcs.hpp"

int main() {
    string s = "abcbdab";
    string t = "bdcaba";
    
    LCS<string> lcs(s, t);
    
    assert(lcs.len == 4);
    
    string s2 = "abc";
    string t2 = "abc";
    LCS<string> lcs2(s2, t2);
    assert(lcs2.len == 3);
    assert(lcs2.lcs == "abc");
    
    string s3 = "abc";
    string t3 = "def";
    LCS<string> lcs3(s3, t3);
    assert(lcs3.len == 0);
    
    cout << "LCS test passed!" << endl;
    return 0;
}
