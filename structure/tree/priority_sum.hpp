#pragma once

#include "structure/tree/implicit_treap.hpp"

template <typename T, bool ascending = true>
struct PrioritySum {
    SumUpdateQuery<T, T> tr;
    MinUpdateQuery<T, T> tr2;
    int cnt = 0;

    void add(T a) {
        int p = tr2.binary_search(0, tr2.size(), a, !ascending);
        if (ascending) {
            tr.insert(p + 1, a);
            tr2.insert(p + 1, a);
        } else {
            if (p == -1) {
                tr.insert(tr.size(), a);
                tr2.insert(tr2.size(), a);
            } else {
                tr.insert(p, a);
                tr2.insert(p, a);
            }
        }
        cnt++;
    }

    void erase_at(int k) {
        assert(0 <= k && k < cnt);
        tr.erase(k);
        tr2.erase(k);
        cnt--;
    }

    void erase_value(T a) {
        int p = tr2.binary_search(0, tr2.size(), a, !ascending);
        if (ascending) {
            if (p == cnt) p = 0;
            p++;
        } else {
            if (p == -1) p = cnt;
            p--;
        }
        assert(0 <= p && p < tr.size() && tr[p] == a);
        erase_at(p);
    }

    int size() const { return cnt; }

    T sum(int k) { return tr.query(0, k); }

    T sum(int l, int r){return tr.query(l,r);}

    T operator[](int k) { return tr[k]; }

    void dump() { tr.dump(); }

    //original from here
    int lower_bound(T a) {
        int p = tr2.binary_search(0, tr2.size(), a, !ascending);
        if (ascending) {
            return p+1;
        } else {
            if (p == -1) {
                return tr.size();
            } else {
                return p;
            }
        }
    }

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

    void erase_all(T a) {
        int p = tr2.binary_search(0, tr2.size(), a, !ascending);
        if (ascending) {
            if (p == cnt) p = 0;
            p++;
        } else {
            if (p == -1) p = cnt;
            p--;
        }
        while(0<=p&&p<size()&&tr[p]==a){
            // assert(0 <= p && p < tr.size() && tr[p] == a);
            erase_at(p);
        }
    }
};