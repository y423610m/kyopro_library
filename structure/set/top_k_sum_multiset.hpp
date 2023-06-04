#pragma once

template <typename T, typename Compare = less<T>>
struct TopKSumMultiSet{
    //LにtopのK個を格納．それ以外はRに格納．
    multiset<T, Compare> L,R;
    T sumL = 0, sumR = 0;
    size_t K;
    TopKSumMultiSet(int K):K(K){}
    //まずLに挿入．LのサイズがK超えたらRに移動
    void insert(T x){
        L.insert(x);
        sumL += x;
        if(L.size()>K){
            auto it = prev(L.end());
            sumR += *it;
            R.insert(*it);
            sumL -= *it;
            L.erase(it);
        }
    }

    //return true if erased
    bool erase(T x){
        auto it = R.find(x);
        if(it!=R.end()){
            sumR -= *it;
            R.erase(it);
            return true;
        }
        it = L.find(x);
        if(it!=L.end()){
            sumL -= *it;
            L.erase(it);
            if(R.size()){
                it = R.begin();
                sumR -= *it;
                L.insert(*it);
                sumL += *it;
                R.erase(it);
            }
            return true;
        }
        return false;
    }

    size_t size(){
        return L.size()+R.size();
    }

    void clear(){
        L.clear();
        R.clear();
        sumL = 0;
        sumR = 0;
    }

    /*
    TopKSumMultiSet<ll> Kst;//小さい方K
    TopKSumMultiSet<ll,greater<ll>> Kst;//大きいほうK
    Kst.insert(a);
    Kst.erase(a);
    EL(Kst.sumL);
    EL(Kst.size());
    EL(Kst.clear());
    //ABC281E
    */
};