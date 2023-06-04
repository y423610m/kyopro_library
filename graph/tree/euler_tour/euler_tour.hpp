#include "graph/graph_template.hpp"
#include "graph/tree/LCA_RMQ.hpp"

template<typename T>
struct EulerTour{
   int N;
   vector<int> depth;//depth[i]:=頂点iの深さ
   vector<int> parent;//parent[i]:=頂点iの親．
   vector<vector<int>> children;//children[i]:=頂点iの直属の子
   vector<int> numOfChildren;//子孫の数．
   vector<T> dist;//dist[i]:=根から頂点iまでのコスト
   vector<int> order;//order[i]:=時刻iに訪れた頂点
   vector<int> in;//頂点iを始めて訪れた時刻
   vector<int> out;//頂点iを出た時刻
   vector<int> dep;//dep[i]:=時刻iの深さ
   LCA_RMQ<T> lca_rmq;


   EulerTour(int N, const Graph<T>& G, int root = 0, bool memoMid = true, bool memoOut = true)
   :N(N)
   ,depth(N,-1)
   ,parent(N,-1)
   ,children(N)
   ,numOfChildren(N, 0)
   ,dist(N, -1)
   ,in(N,-1)
   ,out(N,-1)
   ,lca_rmq(N, G, root)
   {
      
      order.reserve(N+N*memoMid+N*memoOut);
      dep.reserve(N+N*memoMid+N*memoOut);

      parent[root] = -1;
      dist[root] = 0;

      auto dfs = [&](auto dfs, int v, int d)->void {
         depth[v] = d;
         in[v] = order.size();
         order.emplace_back(v);
         dep.emplace_back(d);

         numOfChildren[v] = 0;
         for(const auto& e:G[v]) if(depth[e.to]==-1){
            parent[e.to] = v;
            dist[e.to] = dist[v] + e.cost;
            children[v].emplace_back(e.to);
            dfs(dfs, e.to, d+1);
            numOfChildren[v] += numOfChildren[e.to] + 1;
            if(memoMid){
               order.emplace_back(v);
               dep.emplace_back(d);
            }
         }
         out[v] = order.size();
         if(memoOut){
            order.emplace_back(v);
            dep.emplace_back(d);
         }
      };
      dfs(dfs, root, 0);
   }

   int lca(int x, int y) const{
      return lca_rmq.lca(x, y);
   }

   T distance(int x, int y)const{
      return dist[x]+dist[y]-dist[lca(x,y)]*2;
   }

   int size(){
      return int(order.size());
   }

   bool AinB(int a, int b){
      if(in[b]<in[a]&&in[a]<=out[b]) return true;
      return false;
   }

   //path update
   template<typename F>
   void add(int u, int v, F f, bool edge = false){
      if(in[u]>in[v]) swap(u,v);
      f(in[u]+edge, in[v]+1);
   }

   /*
      int N; cin>>N;
      Edges<int> E = readE<int>(N-1, -1, false);//weighted
      Graph<int> G(N, E, false);//directed
      EulerTour<int> et(N, G, 0);//root
      EulerTour<int> et(N, G, 0, true, true);
      //root, 途中記録する?, out記録? 

      EL(et.lca(0,4))//共通祖先id
      EL(et.distance(0,4))//2点間の距離

      EL(et.parent[1])
      EL(et.depth[1])
      EL(et.dist[1])//rootからのcost距離
      EL(et.numOfChildren[1])
   */
};

