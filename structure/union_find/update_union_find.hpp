
struct UpdateUnionFind {
   vector<int> par;
   vector<int> sz;

   UpdateUnionFind(int n = 1)
   :par(n,-1), sz(n,1)
   {}

   int leader(int x) {
      if (par[x] == -1) {
         return x;
      }
      else {
         int r = leader(par[x]);
         return par[x] = r;
      }
   }

   int operator[](int i){
      return leader(i);
   }

   // const int& operator[](int i)const{
   //    return leader(i);
   // }

   bool same(int x, int y) {
      return leader(x) == leader(y);
   }

   template<typename Cmp, typename F>
   bool merge(int x, int y, Cmp cmp, F f) {
      x = leader(x); y = leader(y);
      if (x == y) return false;
      // if (sz[x] < sz[y]) swap(x, y);
      if (!cmp(x,y)) swap(x, y);
      sz[x] += sz[y];
      par[y] = x;
      // weight[x] = f(weight[x], weight[y]);
      f(x, y);
      return true;
   }

   int size(){
      return sz.size();
   }

   int size(int i){
      return sz[leader(i)];
   }

   /*
   UpdateUnionFind uf(N);
   V<ll> Weight(N);
   rep(i,N) W[i] = A[i];
   auto cmp = [&](int parent, int child)->bool {return uf.sz[parent]>=uf.sz[child];};//マージする際にあるべき状態
   auto f = [&](int parent, int child)->void {Weight[parent] += Weight[child];};//重みに対して行う処理
   if(!uf.same(x,y)) uf.merge(x, y, cmp, f);
   uf.leader(i); == uf[i];
   abc277D2
   abc295G
   abc239F
   agc002c
   */
};