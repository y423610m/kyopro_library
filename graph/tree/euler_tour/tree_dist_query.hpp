#pragma once

#include "graph/tree/euler_tour/euler_tour.hpp"
#include <atcoder/segtree>
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T=ll> using RSQ = atcoder::segtree<T, opSum<T>, e0<T>>;


template <typename T>
struct TreeDistQuery{

   EulerTour<T> et;

   RSQ<T> seg;

   TreeDistQuery(int N, const Graph<T>& G, int root = 0)
   :et(N, G, root, false)
   , seg(et.size())
   {}

   void set(int a, int b, T x){
      if(et.in[a]>et.in[b]) swap(a, b);
      seg.set(et.in[b], x);
      seg.set(et.out[b], -x);
   }

   void add(int a, int b, T x){
      if(et.in[a]>et.in[b]) swap(a, b);
      seg.set(et.in[b], seg.get(et.in[b])+x);
      seg.set(et.out[b], seg.get(et.out[b])+x);
   }

   T query(int a, int b){
      int lca = et.lca(a, b);
      return seg.prod(0, et.in[a]+1) + seg.prod(0, et.in[b]+1) - seg.prod(0, et.in[lca]+1) * 2;
   }
};