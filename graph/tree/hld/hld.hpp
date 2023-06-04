#pragma once

#include "graph/graph_template.hpp"

template <typename T>
struct HLD{
   int N;
   vector<int> sz;
   vector<int> in;
   vector<int> out;
   vector<int> head;//頂点iの属する成分の根
   vector<int> parent;
   vector<int> order;//時刻iに通る頂点
   vector<int> depth;//頂点iの深さ

   HLD(int N, Graph<T>& G, int root = 0)
   :N(N),
   sz(N, 0), 
   in(N, 0), 
   out(N, 0), 
   head(N, 0), 
   parent(N, 0), 
   order(N, 0), 
   depth(N, 0)
   {
      auto dfs_sz = [&](auto dfs_sz, int p, int par, int d)->void {
         depth[p] = d;
         parent[p] = par;
         sz[p] = 1;
         for(auto& e:G[p]) if(e.to!=par){
            dfs_sz(dfs_sz, e.to, p, d+1);
            sz[p] += sz[e.to];
            //一番大きな部分木を先頭に
            if(sz[G[p][0].to] < sz[e.to]) swap(G[p][0], e);
         }
      };
      dfs_sz(dfs_sz, root, -1, 0);

      int t = 0;
      auto dfs_hld = [&](auto dfs_hld, int p, int par)->void {
         in[p] = t++;
         order[in[p]] = p;
         for(auto& e:G[p]) if(e.to!=par){
            head[e.to] = (G[p][0].to==e.to? head[p]:e.to);
            dfs_hld(dfs_hld, e.to, p);
         }
         out[p] = t;
      };
      dfs_hld(dfs_hld, root, -1);
   }





   int la(int v, int k){
      while(1){
         int u = head[v];
         if(in[v] - k >= in[u]) return order[in[v]-k];
         k -= in[v] - in[u] + 1;
         v = parent[u];
      }
   }

   int lca(int u, int v){
      for(;; v = parent[head[v]]){
         if(in[u] > in[v]) swap(u,v);
         if(head[u] == head[v]) return u;
      }
   }

   int dist(int u, int v){
      return depth[u] + depth[v] - depth[lca(u,v)]*2;
   }

   template <typename Q>
   void add(int u, int v, const Q q, bool edge = false){
      for(;;v = parent[head[v]]){
         if(in[u] > in[v]) swap(u, v);
         if(head[u] == head[v]) break;
         q(in[head[v]], in[v] + 1);
      }
      q(in[u]+edge, in[v]+1);
   }

   template<typename E, typename Q, typename F, typename S >
   E query(int u, int v, const E e, const Q& q, const F& f, const S& s, bool edge = false){
      E l = e, r = e;
      for(;;v = parent[head[v]]){
         if(in[u] > in[v]) swap(u, v), swap(l, r);
         if(head[u] == head[v]) break;
         l = f(q(in[head[v]], in[v]+1), l);
      }
      return s(f(q(in[u]+edge, in[v]+1), l), r);
   }

   template<typename E, typename Q, typename F>
   E query(int u, int v, const E& e, const Q& q, const F& f, bool edge = false){
      return query(u, v, e, q, f, f, edge);
   }

};

/*

*/