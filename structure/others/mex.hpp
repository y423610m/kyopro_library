#pragma once

#include "atcoder/segtree"

namespace MEX{
   template <typename cntT, typename T> pair<cntT, T> _opMin(pair<cntT, T> a, pair<cntT, T> b){return min(a,b);}
   template <typename cntT, typename T> pair<cntT, T> _e0(){return {0, numeric_limits<T>::max()};}
}

template <typename T>
struct Mex{
   using cntT = int;
   using P = pair<cntT, T>;

   atcoder::segtree<P, MEX::_opMin<cntT, T>, MEX::_e0<cntT, T>> seg;
   cntT N;

   Mex(int N)
   :seg(N+1),
   N(N)
   {
      for(int i=0;i<N+1;i++){
         seg.set(i, {cntT(0), T(i)});
      }
   }

   void insert(const T& x, cntT num=1){
      if(T(0)<=T(x) && T(x)<T(N)){
         EL("a")
         P p = seg.get(T(x));
         p.fi += cntT(num);
         ES(x) EL(p)
         seg.set(x, p);
      }
   }

   void erase(const T& x, cntT num=1){
      if(T(0)<=T(x) && T(x)<T(N)){
         P p = seg.get(T(x));
         p.fi -= cntT(num);
         seg.set(x, p);
      }
   }

   T mex(){
      return seg.prod(0, N+1).se;
   }
};