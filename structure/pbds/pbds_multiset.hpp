#pragma once
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;


template<typename T, typename Compare = less<pair<T, int> >, typename tag = rb_tree_tag>
struct PBDSMultiset{
    //splay_tree_tag
    using P = pair<T,int>;
    unordered_map<T,int> cnt;
    tree<P, null_type, Compare, tag, tree_order_statistics_node_update> st;
    int l,r;
    PBDSMultiset(){
        l = numeric_limits<int>::min()/2+1;
        r = numeric_limits<int>::max()/2-1;
        if(!Compare()(P(T(), l), P(T(),r))) swap(l, r);
    }

    void insert(T x){
        st.insert({x, cnt[x]++});
    }

    T operator[](int i){
        return st.find_by_order(i)->fi;
    }

    int lower_bound(T x){
        return st.order_of_key(P{x, l});
    }

    int upper_bound(T x){
        return st.order_of_key(P{x, r});
    }

    int find(T x){
        int id = st.order_of_key(P{x, l});
        if(id<st.size()&&st.find_by_order(id)->fi==x) return id;
        else return st.size();
    }

    bool erase(T x){
        int id = st.order_of_key(P(x, l));
        if(id<st.size()){
            auto it = st.find_by_order(id);
            if(it->fi==x){
                st.erase(it);
                return true;
            }
        }
        return false;
    }

    bool erase_at(int k){
        if(k<0||st.size()<=k) return false;
        st.erase(st.find_by_order(k));
        return true;
    }

    int size(){
        return st.size();
    }

    T front(){
        return st.find_by_order(0);
    }

    T back(){
        return st.find_by_order(st.size()-1);
    }

    bool pop_front(){
        return erase_at(0);
    }

    bool pop_back(){
        return erase_at(st.size()-1);
    }

    /*
        // PBDSMultiset<ll, greater<pair<ll,int>>> st;
        PBDSMultiset<ll> st;
        rep(i,10) st.insert(i);
        int id = st.lower_bound(4);
        EL(id)
        EL(st[id])
        repi(i,2,5) st.erase(i);
        rep(i,st.size()) PL(st[i])
    */
};