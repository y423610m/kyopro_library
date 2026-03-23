#include <bits/stdc++.h>
using namespace std;

#include "../../structure/trie/trie.hpp"

int main() {
    Trie<26, 'a'> tr;
    
    tr.insert("apple");
    tr.insert("app");
    tr.insert("banana");
    tr.insert("band");
    
    assert(tr.count() == 4);
    
    int id1 = tr.find("app");
    assert(tr[id1].depth == 3);
    
    assert(tr.lcp_len("apple", "app") == 3);
    assert(tr.lcp_len("banana", "band") == 3);
    assert(tr.lcp_len("apple", "banana") == 0);
    
    int idx = tr.is_Kth("app");
    assert(idx >= 0);
    
    cout << "Trie test passed!" << endl;
    return 0;
}
