#pragma once

#include "graph/graph_template.hpp"

template<typename EdgeT, typename VertexT>
struct RerootingDP {

   int n, root;
   vector<vector<EdgeT>> outs;
   vector<EdgeT> reverse_edge;
   vector<VertexT> answers;

   RerootingDP() = default;

   template<typename GraphT, typename MergeT, typename ElT, typename PET, typename PVT>
   VertexT build(int _n, Graph<GraphT>& G, int _root, MergeT& Merge, ElT& El, PET& Put_Edge, PVT& Put_Vertex){
      n = _n;
      root = _root;
      outs.resize(n);

      auto dfs = [&](auto& dfs, int v, int parent = -1)->VertexT {
         EdgeT val = El(v, false);
         for(auto& e:G[v]){//swapのため，非const
            if(e.to == parent && e.to != G[v].back().to) swap(e, G[v].back());
            if(e.to == parent) continue;
            
            EdgeT nval = Put_Edge(dfs(dfs, e.to, v), e);
            outs[v].emplace_back(nval);
            val = Merge(val,nval);
         }
         return Put_Vertex(val,v);
      };

      return dfs(dfs, root);
   }

   template<typename GraphT, typename MergeT, typename ElT, typename PET, typename PVT>
   vector<VertexT> reroot(Graph<GraphT>& G, MergeT& Merge, ElT& El, PET& Put_Edge, PVT& Put_Vertex){
      //El(vertexid, canAffectSelf):answer[vertexid]に影響を与える時はtrueいれておく
      reverse_edge.resize(n);
      reverse_edge[root] = El(root, true);
      answers.resize(n);

      auto bfs = [&](auto& bfs, int v)->void {
         int siz = outs[v].size();
         vector<EdgeT> lui(siz+1), rui(siz+1);
         lui[0] = El(v, true), rui[siz] = El(v, false);
         for (int i = 0; i < siz; i++) lui[i+1] = Merge(lui[i],outs[v][i]);
         for (int i = siz-1; i >= 0; i--) rui[i] = Merge(outs[v][i],rui[i+1]);
         for (int i = 0; i < siz; i++){
            reverse_edge[G[v][i].to] = Put_Edge(Put_Vertex(Merge(Merge(lui[i],rui[i+1]),reverse_edge[v]),v),G[G[v][i].to].back());
            bfs(bfs, G[v][i].to);
         }
         answers[v] = Put_Vertex(Merge(lui[siz],reverse_edge[v]), v);
      };

      bfs(bfs, root);
      return answers;
   }

};



/*
   ll N; cin>>N;
   Edges<ll> E = readE<ll>(N-1, -1, false);//weighted?
   Graph<ll> G(N, E, false);//directed?

   using EdgeT = ll;
   using VertexT = ll;
   auto Merge = [&](EdgeT a, EdgeT b)->EdgeT {
      return max(a,b);
   };
   auto El = [&](int p, bool canAffectSelf = false)->EdgeT {
      if(canAffectSelf) return 0;
      return 0;
   };
   auto PE = [&](VertexT v, const Edge<ll>& e)->EdgeT {
      return v + e.cost;
   };
   auto PV = [&](EdgeT e, int p)->VertexT {
      return e;
   };

   RerootingDP<EdgeT, VertexT> rdp;
   rdp.build(N, G, 0, Merge, El, PE, PV);
   auto dp = rdp.reroot(G, Merge, El, PE, PV);

   vertex:その頂点を根とした値を考えるとき
   edge:根以外の木の一部にするとき．
*/

