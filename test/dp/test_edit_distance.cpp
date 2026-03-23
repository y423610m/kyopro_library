#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../../dp/edit_distance.hpp"

int main() {
    string S = "abc";
    string T = "abcd";
    
    EditDistance ed;
    ll dist = ed.solve(S, T);
    assert(dist == 1);
    
    string S2 = "kitten";
    string T2 = "sitting";
    EditDistance ed2;
    ll dist2 = ed2.solve(S2, T2);
    assert(dist2 == 3);
    
    cout << "EditDistance test passed!" << endl;
    return 0;
}
