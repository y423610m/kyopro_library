#pragma once

template<typename T=int, typename U=int>
struct UnorderedMapWeightUpdateUnionFind{
   unordered_set<T> st;
   unordered_map<T,T> par;
   unordered_map<T,int> sz;
   unordered_map<T,U> weight;

   UnorderedMapWeightUpdateUnionFind(int N=1){
      st.reserve(N);
      par.reserve(N);
      sz.reserve(N);
      weight.reserve(N);
   }

   void check(T a){
      if(st.find(a)==st.end()){
         st.insert(a);
         par[a] = a;
         sz[a] = 1;
         weight[a] = 0;
      }
   }

   T leader(T x, bool first = true){
      if(first) check(x);
      if(par[x]==x) return x;
      T l = leader(par[x], false);
      return par[x] = l;
   }

   T& operator[](int i){
      check(i);
      return weight[leader(i)];
   }

   const T& operator[](int i)const{
      check(i);
      return weight[leader(i)];
   }

   bool same(T a, T b){
      return leader(a)==leader(b);
   }

   template<typename Cmp, typename F>
   bool merge(T x, T y, Cmp cmp, F f){
      x = leader(x);
      y = leader(y);
      if(x==y) return false;
      // if(sz[x]<sz[y]) swap(x,y);
      if(!cmp(x,y)) swap(x,y);
      par[y] = x;
      sz[x] += sz[y];
      // weight[x] = f(weight[x], weight[y]);
      f(x,y);
      return true;
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
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {uf.weight[parent] += uf.weight[child];};//重みに対して行う処理
   if(!uf.same(x,y))uf.merge(x,y,cmp,f);
   EL(uf.size())//全体
   EL(uf.size(x))//xの属するサイズ
   EL(uf.leader(x))//xのリーダー．新規，単体は-1を返す
   for(auto x:uf.st)//含まれてる頂点走査
   uf[x] = 1;//リーダーにアクセスされる．
   ABC277C
   */
};