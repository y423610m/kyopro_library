#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include <atcoder/internal_bit.hpp>


template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
   segtree() : segtree(0) {}
   explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
   explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
      log = internal::ceil_pow2(_n);
      size = 1 << log;
      d = std::vector<S>(2 * size, e());
      for (int i = 0; i < _n; i++) d[size + i] = v[i];
      for (int i = size - 1; i >= 1; i--) {
         update(i);
      }
   }

   void set(int p, S x) {
      assert(0 <= p && p < _n);
      p += size;
      d[p] = x;
      for (int i = 1; i <= log; i++) update(p >> i);
   }

   void add(int p, S x) {
      assert(0 <= p && p < _n);
      p += size;
      d[p] = d[p] + x;
      for (int i = 1; i <= log; i++) update(p >> i);
   }

   S get(int p) const {
      assert(0 <= p && p < _n);
      return d[p + size];
   }

   S prod(int l, int r) const {
      assert(0 <= l && l <= r && r <= _n);
      S sml = e(), smr = e();
      l += size;
      r += size;

      while (l < r) {
         if (l & 1) sml = op(sml, d[l++]);
         if (r & 1) smr = op(d[--r], smr);
         l >>= 1;
         r >>= 1;
      }
      return op(sml, smr);
   }

   S all_prod() const { return d[1]; }

   template <bool (*f)(S)> int max_right(int l) const {
      return max_right(l, [](S x) { return f(x); });
   }
   template <class F> int max_right(int l, F f) const {
      assert(0 <= l && l <= _n);
      assert(f(e()));
      if (l == _n) return _n;
      l += size;
      S sm = e();
      do {
         while (l % 2 == 0) l >>= 1;
         if (!f(op(sm, d[l]))) {
               while (l < size) {
                  l = (2 * l);
                  if (f(op(sm, d[l]))) {
                     sm = op(sm, d[l]);
                     l++;
                  }
               }
               return l - size;
         }
         sm = op(sm, d[l]);
         l++;
      } while ((l & -l) != l);
      return _n;
   }

   template <bool (*f)(S)> int min_left(int r) const {
      return min_left(r, [](S x) { return f(x); });
   }
   template <class F> int min_left(int r, F f) const {
      assert(0 <= r && r <= _n);
      assert(f(e()));
      if (r == 0) return 0;
      r += size;
      S sm = e();
      do {
         r--;
         while (r > 1 && (r % 2)) r >>= 1;
         if (!f(op(d[r], sm))) {
               while (r < size) {
                  r = (2 * r + 1);
                  if (f(op(d[r], sm))) {
                     sm = op(d[r], sm);
                     r--;
                  }
               }
               return r + 1 - size;
         }
         sm = op(d[r], sm);
      } while ((r & -r) != r);
      return 0;
   }

private:
   int _n, size, log;
   std::vector<S> d;

   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};



/*
template<typename T> T opMax(T a, T b){return max(a,b);}
template<typename T> T opMin(T a, T b){return min(a,b);}
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T> T e_LINF(){return -LINF;}
template<typename T> T eLINF(){return LINF;}

template<typename T=ll> using RMQ = segtree<T, opMax<T>, e_LINF<T>>;//Range Max Query
template<typename T=ll> using RmQ = segtree<T, opMin<T>, eLINF<T>>;// RmQ tree(vec); tree.prod(l,r)
template<typename T=ll> using RSQ = segtree<T, opSum<T>, e0<T>>;

ll seg_target;
bool f(ll vi){return vi<seg_target;}//seg.max_right<f>(x-1)
bool f2(ll vi){return vi>=seg_target;}//seg.max_right<f>(x-1)
//max_right<f>(l):=>[l:N)でfを満たす右端．
//min_left<f>(r):=>[0:r)でfを満たす左端．
//f(e)=trueでなければならない
//RMQ<ll> tree(N);
//tree.set(i,0);
//tree.get(i);
//tree.prod(l,r);//半開区間
*/