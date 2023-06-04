#pragma once

#include "structure/tree/implicit_treap.hpp"

template <typename T, bool ascending = true>
struct ordered_multiset {
    MinUpdateQuery<T, T> tr2;
    int cnt = 0;

    void insert(T a) {
        int p = tr2.binary_search(0, tr2.size(), a, !ascending);
        if (ascending) {
            tr2.insert(p + 1, a);
        } else {
            if (p == -1) {
                tr2.insert(tr2.size(), a);
            } else {
                tr2.insert(p, a);
            }
        }
        cnt++;
    }

    void erase_at(int k) {
        //assert(0 <= k && k < cnt);
        if(k<0||cnt<=k) return;
        tr2.erase(k);
        cnt--;
    }

    void erase(T a) {
        while(1){
            int p = tr2.binary_search(0, tr2.size(), a, !ascending);
            if (ascending) {
                if (p == cnt) p = 0;
                p++;
            } else {
                if (p == -1) p = cnt;
                p--;
            }
            //assert(0 <= p && p < tr2.size() && tr2[p] == a);
            if(0 <= p && p < tr2.size()&&tr2[p]==a) erase_at(p);
            else break;
        }
    }

    int size() const { return cnt; }

    T operator[](int k) { return tr2[k]; }

    void dump() { tr2.dump(); }

    //original from here
    int lower_bound(T a) {
        int p = tr2.binary_search(0, tr2.size(), a, !ascending);
        if (ascending) {
            return p+1;
        } else {
            if (p == -1) {
                if(0<=tr2.size()-1&&tr2.size()-1<cnt&&tr2[tr2.size()-1]==a) return tr2.size()-1;
                return tr2.size();
            } else {
                if(0<=p-1&&p-1<cnt&&tr2[p-1]==a) return p-1;
                if(p<0||cnt<=p||tr2[p]==a) return p;
                return p;
            }
        }
    }

    int find(T a){
        int p = tr2.binary_search(0, tr2.size(), a, !ascending);
        if (ascending) {
            if(p+1<0||cnt<=p+1||tr2[p+1]!=a) return cnt;
            return p+1;
        } else {
            if (p == -1) {
                if(0<=tr2.size()-1&&tr2.size()-1<cnt&&tr2[tr2.size()-1]==a) return tr2.size()-1;
                return tr2.size();
            } else {
                if(0<=p-1&&p-1<cnt&&tr2[p-1]==a) return p-1;
                if(p<0||cnt<=p||tr2[p]==a) return p;
                return cnt;
            }
        }
    }

    T front(){return tr2[0];}

    T back(){return tr2[cnt-1];}

    // int upper_bound(T a) {
    //     if(ascending) a++;
    //     else a--;
    //     int p = tr2.binary_search(0, tr2.size(), a, !ascending);
    //     if (ascending) {
    //         return p+1;
    //     } else {
    //         if (p == -1) {
    //             return tr.size();
    //         } else {
    //             return p;
    //         }
    //     }
    // }

    // void erase_all(T a) {
    //     int p = tr2.binary_search(0, tr2.size(), a, !ascending);
    //     if (ascending) {
    //         if (p == cnt) p = 0;
    //         p++;
    //     } else {
    //         if (p == -1) p = cnt;
    //         p--;
    //     }
    //     while(0<=p&&p<size()&&tr2[p]==a){
    //         // assert(0 <= p && p < tr.size() && tr[p] == a);
    //         erase_at(p);
    //     }
    // }

    /*
    ll N; cin>>N;
    ordered_multiset<ll,true> st;
    rep(i,N)st.insert(i);
    rep(i,N)st.insert(i);
    rep(i,N)st.insert(i);
    repi(i,-2,N+3){ES(i) EL(st.find(i))}
    repi(i,-2,N+3){ES(i) EL(st.lower_bound(i))}
    st.dump();
    st.erase(N+10);
    st.dump();
    rep(i,N) st.erase(i);
    st.dump();

    verify
    ABC134C
    */
};