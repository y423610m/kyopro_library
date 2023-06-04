#pragma once

#include "structure/tree/implicit_treap.hpp"

template<typename T>
struct TreapRollingHash{
    SumAffineQuery<T> tree;
    vector<T> power;
    ll b;
    T inv;
    TreapRollingHash(ll b)
    :b(b)
    ,power(1,1)
    ,inv(T(1)/b)
    {}

    void insert(int i, T x){
        ll d = tree.size()-i;
        expand(d);
        if(i>=0) tree.update(0,i, {b,0});
        tree.insert(i,x*power[d]);
    }

    void erase(int i){
        ll d = tree.size()-i;
        expand(d);
        tree.erase(i);
        tree.update(0, i, {inv, 0});
    }

    T query(int l, int r){
        ll d = tree.size()-r;
        expand(d);
        return tree.query(l,r)/power[d];
    }

    void expand(int n){
        while(power.size()<=n){
            power.emplace_back(power.back()*b);
        }
    }

    int size(){
        return tree.size();
    }

    void dump(){
        tree.dump();
    }
/*
#include "string/treap_rolling_hash.hpp"
TreapRollingHash<mint> rh(11);//b
rep(i,S.size()){rh.insert(i,S[i]);}
rh.size();
rh.query(l,r);
rh.dump();
rh.erase();
*/
};