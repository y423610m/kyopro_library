#pragma once

#include "atcoder/lazysegtree"
using namespace atcoder;

namespace LongContinuousBits{
   template<typename T>
   struct S{
      T lenL=1;
      T lenR=1;
      T long0=1;
      T long1=0;
      bool isL1 = false;
      bool isR1 = false;
      T num0 = 1;
      T num1 = 0;
      ll size=1;
   };

   template<typename T> S<T> GetS1(){
      S<T> s;
      s.long0 = 0;
      s.long1 = 1;
      s.isL1 = true;
      s.isR1 = true;
      s.num0 = 0;
      s.num1 = 1;
      return s;
   }


   template<typename T>
   struct F{
      T nxt0 = 0;
      T nxt1 = 1;
   };

   template<typename T> S<T> opMax(const S<T>& l, const S<T>& r){
      S<T> s;
      s.lenR = r.lenR;
      s.lenL = l.lenL;
      s.isL1 = l.isL1;
      s.isR1 = r.isR1;
      s.long1 = max(r.long1, l.long1);
      s.long0 = max(r.long0, l.long0);
      if(l.isR1&&r.isL1){
         if(s.long1 < l.lenR + r.lenL){
            s.long1 = l.lenR + r.lenL;
            if(l.lenR==l.size) s.lenL = s.long1;
            if(r.lenL==r.size) s.lenR = s.long1;
         }
      }
      if(!l.isR1&&!r.isL1){
         if(s.long0 < l.lenR + r.lenL){
            s.long0 = l.lenR + r.lenL;
            if(l.lenR==l.size) s.lenL = s.long0;
            if(r.lenL==r.size) s.lenR = s.long0;
         }
      }
      s.num0 = l.num0 + r.num0;
      s.num1 = l.num1 + r.num1;
      s.size = l.size + r.size;
      return s;
   }

   template<typename T> S<T> e(){return S<T>();}

   template<typename T>
   S<T> FS(const F<T>& f, S<T> s){
      //全部塗りつぶす
      if(f.nxt0 == f.nxt1){
         s.isR1 = f.nxt0;//nxt==1
         s.isL1 = f.nxt0;
         s.lenR = s.size;
         s.lenL = s.size;
         if(f.nxt0==1) s.long1 = s.size;
         else s.long1 = 0;
         s.long0 = s.size - s.long1;
         s.num0 = s.long0;
         s.num1 = s.long1;
      }
      else if(f.nxt0==1){
         s.isR1 ^= 1;
         s.isL1 ^= 1;
         swap(s.long1, s.long0);
         swap(s.num0, s.num1);
      }
      // else nxt0==0 && nxt1==1 は特に何もしない
      return s;
   }

   template<typename U=ll>
   F<U> FF(F<U> l, const F<U>& r){
      if(l.nxt0==0) l.nxt0 = r.nxt0;
      else l.nxt0 = r.nxt1;
      if(l.nxt1==0) l.nxt1 = r.nxt0;
      else l.nxt1 = r.nxt1;
      return l;
   }

   template<typename U=ll>
   F<U> f(){
      return F<U>();
   }
   template<typename T=ll> using LazyRMQ = lazy_segtree<S<T>, opMax<T>, e<T>, F<T>, FS<T>, FF<T>, f<T>>;

}