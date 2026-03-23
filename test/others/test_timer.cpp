#include <bits/stdc++.h>
using namespace std;

#define ES(a) while(0){}
#define EL(a) while(0){}

#include "../../utils/timer.hpp"

int main() {
    Timer t;
    
    for(int i = 0; i < 1000000; i++) {
        int x = i * i;
    }
    int elapsed = t.time();
    
    assert(elapsed >= 0);
    assert(!t.pass(1000000));
    
    cout << "Timer test passed!" << endl;
    return 0;
}
