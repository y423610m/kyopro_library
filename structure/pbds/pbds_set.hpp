#pragma once
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;


template<typename T, typename Compare = less<T>, typename tag = rb_tree_tag>
struct PBDSSet{
    //splay_tree_tag
    tree<T, null_type, Compare, tag, tree_order_statistics_node_update> st;
    void insert(T x){
        st.insert(x);
    }

    T operator[](int i){
        return *st.find_by_order(i);
    }

    T operator[](int i)const{
        return *st.find_by_order(i);
    }

    int lower_bound(T x){
        return st.order_of_key(x);
    }

    int upper_bound(T x){
        if(contains(x)) return lower_bound(x)+1;
        return lower_bound(x);
    }

    int find(T x){
        int id = st.order_of_key(x);
        if(id<st.size()&&*st.find_by_order(id)==x) return id;
        else return st.size();
    }

    int contains(T x){
        return find(x)!=st.size();
    }

    bool erase(T x){
        int id = st.order_of_key(x);
        if(id<st.size()){
            auto it = st.find_by_order(id);
            if(*it==x){
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

    int size()const{
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
        PBDSSet<ll, greater<ll>> st;
        rep(i,10) st.insert(i);
        st.erase(5);
        rep(i,st.size()) EL(st[i])
        EL(st.lower_bound(7))
        EL(st.find(-1))
    */
};

template<typename T, typename Compare = less<T>, typename tag = rb_tree_tag>
ostream& operator<<(ostream& os, const PBDSSet<T, Compare, tag>& st){
    for(int i=0;i<st.size();i++) os << st[i] << " ";
    return os;
}