#pragma once

#include "graph/tree/euler_tour/euler_tour.hpp"
#include <atcoder/segtree>
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T=ll> using RSQ = atcoder::segtree<T, opSum<T>, e0<T>>;



template <typename T>
struct DirectedTreeDistQuery{

   EulerTour<T> et;

   RSQ<T> segDown;
   RSQ<T> segUp;

   //edge:辺の始点出発時刻
   //node:

   DirectedTreeDistQuery(int N, const Graph<T>& G, int root = 0)
   :et(N, G, root, true)
   , segDown(et.size())
   , segUp(et.size())
   {
      for(int i=0;i<N;i++){
         for(const auto& e:G[i]){
            set(e.from, e.to, e.cost);
         }
      }
   }

   void set(int a, int b, T x){
      if(et.in[a]<et.in[b]){
         segDown.set(et.in[b], x);
         segDown.set(et.out[b], -x);
      }
      else{
         swap(a, b);
         segUp.set(et.in[b], x);
         segUp.set(et.out[b], -x);
      }
   }

   void add(int a, int b, T x){
      if(et.in[a]<et.in[b]){
         segDown.set(et.in[b], segDown.get(et.in[b])+x);
         segDown.set(et.out[b], segDown.get(et.out[b])-x);
      }
      else{
         swap(a, b);
         segUp.set(et.in[b], segUp.get(et.in[b])+x);
         segUp.set(et.out[b], segUp.get(et.out[b])-x);
      }
   }

   T query(int a, int b){
      int l = et.lca(a, b);
      return segUp.prod(0, et.in[a]+1) - segUp.prod(0, et.in[l]+1) + segDown.prod(0, et.in[b]+1) - segDown.prod(0, et.in[l]+1);
      // T ans = 0;
      // if(et.in[a]<et.in[l]) ans += segDown.prod(0, et.in[l]+1) - segDown.prod(0, et.in[a]+1);
      // else                  ans += segUp.prod(0, et.in[a]+1) - segUp.prod(0, et.in[l]+1);
      // if(et.in[l]<et.in[b]) ans += segDown.prod(0, et.in[b]+1) - segDown.prod(0, et.in[l]+1);
      // else                  ans += segUp.prod(0, et.in[l]+1) - segUp.prod(0, et.in[b]+1);
      // return ans;
   }
};