///https://atcoder.jp/contests/practice2/tasks/practice2_b

#include <bits/stdc++.h>
using namespace std;

#include "segtree.hpp"

using ll = long long;

ll operation(ll a, ll b)
{
    return a+b;
}

ll e()
{
    return 0;
}


int main(){
    int N, Q;
    cin>>N>>Q;
    vector<int> A(N);
    for(int i=0; i<N;i++) cin>>A[i];
    SegmentTree<ll, operation, e> seg(N);
    for(int i=0; i<N;i++) seg.Set(i, A[i]);
    
    for(int q=0; q<Q; q++) {
      int t; cin>>t;
      if(t==0) {
        int x, v;
        cin>>x>>v;
        //x--;
        seg.Set(x, seg.Get(x)+v);
      }
      else{
        int l,r;
        cin>>l>>r;
        //l--;
        cout << seg.Product(l, r) << endl;
      }
    }
    
}