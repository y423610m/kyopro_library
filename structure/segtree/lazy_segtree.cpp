/// https://atcoder.jp/contests/practice2/tasks/practice2_l

#include <bits/stdc++.h>
using namespace std;

#include "lazy_segtree.hpp"

struct S{
    long long positive = 0;
    long long negative = 0;
    long long inversion = 0;
};

S Operation(S l, S r)
{
    return S{
        l.positive+r.positive, 
        l.negative+r.negative, 
        l.inversion+r.inversion + l.positive*r.negative};
};

S GetE()
{
    return S();
}

struct F
{
    bool reverse = false;
};

S Mapping(F f, S s)
{
    if(f.reverse) {
        return S{
            s.negative,
            s.positive,
            s.negative*s.positive-s.inversion
        };
    }
    return s;
}

F Convolution(F f1, F f2)
{
    return F{bool(f1.reverse ^ f2.reverse)};
};

F GetId()
{
    return F();
}


int main(){
    int N, Q; cin>>N>>Q;
    LazySegtree<S, Operation, GetE, F, Mapping, Convolution, GetId> seg(N);
    
    for(int i=0; i<N; i++) {
        int a;
        cin>>a;
        seg.Set(i, S{a, !a, 0});
    }

    // S s = Operation(S{1,0,0}, S{0, 1, 0});
    S s = Operation(S{0,1,0}, S{1, 0, 0});
    // cout << s.positive<< " " << s.negative<<" " << s.inversion << endl;

    for(int q=0; q<Q; q++) {
        int t, l, r;
        cin>>t>>l>>r;
        l--;
        if(t==1) {
            seg.Apply(l, r, F{1});
        }
        else{
            cout << seg.Product(l, r).inversion << endl;
        }
    }
    
}