#pragma once

template<typename T=int, typename U=int>
struct UnorderedMapWeightedUnionFind{
    unordered_set<T> st;
    unordered_map<T,T> par;
    unordered_map<T,int> sz;
    unordered_map<T,U> diff_weight;

    UnorderedMapWeightedUnionFind(int N=1){
        st.reserve(N);
        par.reserve(N);
        sz.reserve(N);
        diff_weight.reserve(N);
    }

    void check(T a){
        if(st.find(a)==st.end()){
            st.insert(a);
            par[a] = a;
            sz[a] = 1;
            diff_weight[a] = 0;
        }
    }

    T leader(T x, bool first = true){
        if(first) check(x);
        if(par[x]==x) return x;
        T l = leader(par[x], false);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = l;
    }

    U weight(T x){
        leader(x);
        return diff_weight[x];
    }

    U& operator[](T i){
        check(i);
        return diff_weight[i];
    }

    const U& operator[](T i)const{
        check(i);
        return diff_weight[i];
    }

    bool same(T a, T b){
        return leader(a)==leader(b);
    }

    bool merge(T x, T y, U w){
        w += weight(x); w -= weight(y);
        x = leader(x);
        y = leader(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y), w = -w;
        par[y] = x;
        sz[x] += sz[y];
        diff_weight[y] = w;
        return true;
    }

    U diff(T x, T y) {
        return weight(y) - weight(x);
    }

    size_t size(){
        return st.size();
    }

    int size(T x){
        check(x);
        return sz[leader(x,false)];
    }
    /*
    頂点型，重み型
    UnorderedMapWeightSumUnionFind<int, int> uf(N*3);//reserve数
    if(!uf.same(x,y))uf.merge(x,y);
    EL(uf.size())//全体
    EL(uf.size(x))//xの属するサイズ
    EL(uf.leader(x))//xのリーダー．新規，単体は-1を返す
    for(auto x:uf.st)//含まれてる頂点走査
    uf[x] = 1;
    ABC277C
    */
};