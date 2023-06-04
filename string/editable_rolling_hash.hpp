#pragma once

#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
template<typename T> T opMax(T a, T b){return max(a,b);}
template<typename T> T opMin(T a, T b){return min(a,b);}
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T> T e_LINF(){return -LINF;}
template<typename T> T eLINF(){return LINF;}

template<typename T=ll> using RMQ = segtree<T, opMax<T>, e_LINF<T>>;//Range Max Query
template<typename T=ll> using RmQ = segtree<T, opMin<T>, eLINF<T>>;// RmQ tree(vec); tree.prod(l,r)
template<typename T=ll> using RSQ = segtree<T, opSum<T>, e0<T>>;

ll seg_target;
bool f(ll vi){return vi<seg_target;}//seg.max_right<f>(x-1)
bool f2(ll vi){return vi>=seg_target;}//seg.max_right<f>(x-1)
//max_right<f>(l):=>[l:N)でfを満たす右端．
//min_left<f>(r):=>[0:r)でfを満たす左端．
//f(e)=trueでなければならない
//RMQ<ll> tree(N);
//tree.set(i,0);
//tree.get(i);
//tree.prod(l,r);//半開区間
#endif

template<typename T>
struct EditableRollingHash{
    RSQ<T> tree;
    vector<T> power;
    ll b;
    EditableRollingHash(ll N, ll b)
    :tree(N)
    ,power(N)
    ,b(b)
    {
        power[N-1] = 1;
        for(int i=N-2;i>=0;i--) power[i] = power[i+1] * b;
        // power[0] = 1;
        // for(int i=0;i<N-1;i++) power[i+1] = power[i] * b;
    }

    void set(int i, ll x){
        tree.set(i, power[i]*x);
    }

    T get(int i){
        return tree.get(i);
    }

    T prod(int l, int r){
        return tree.prod(l,r)/power[r-1];
    }
};