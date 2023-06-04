#pragma once

template<typename T=int>
struct UnorderedMapUnionFind{
    unordered_set<T> st;
    unordered_map<T,T> par;
    unordered_map<T,int> sz;

    UnorderedMapUnionFind(int N=1){
        st.reserve(N);
        par.reserve(N);
        sz.reserve(N);
    }

    void check(T a){
        if(st.find(a)==st.end()){
            st.insert(a);
            par[a] = a;
            rank[a] = 0;
            sz[a] = 1;
        }
    }

    T leader(T x, bool first = true){
        if(first) check(x);
        if(par[x]==x) return x;
        T l = leader(par[x], false);
        return par[x] = l;
    }

    bool same(T a, T b){
        return leader(a)==leader(b);
    }

    bool merge(T x, T y){
        x = leader(x);
        y = leader(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        par[y] = x;
        sz[x] += sz[y];
        return true;
    }

    size_t size(){
        return st.size();
    }

    int size(T x){
        return sz[leader(x,false)];
    }
    /*
    UnorderedMapUnionFind uf(N*3);//reserve数
    if(!uf.same(x,y))uf.merge(x,y);
    EL(uf.size())//全体
    EL(uf.size(x))//xの属するサイズ
    EL(uf.leader(x))//xのリーダー．新規，単体は-1を返す
    for(auto x:uf.st)//含まれてる頂点走査
    ABC277C
    */
};