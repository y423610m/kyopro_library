#pragma once

template<typename T> struct RKQ{

   void build(vector<T> inV){
      A = inV;
      B = A;
      C = A;
      N = A.size();
      bs = sqrt(N)+1;
      for(ll i=0;i*bs<B.size();i++) sort(B.begin()+i*bs, B.begin()+min((i+1)*bs, N));
      sort(C.begin(), C.end());
      // EL(A)
      // EL(B)
      // EL(bs)
   }

   ll count(ll L, ll R, ll x){
      // [L,R)にx以下の数がいくつあるか
      ll n = 0;

      for(;L%bs!=0&&L<R;L++) if(A[L]<=x) n++;
      for(;R%bs!=0&&L<R;R--) if(A[R-1]<=x) n++;
      for(ll i=L/bs;i*bs+bs<=R;i++){
         n += upper_bound(B.begin()+i*bs, B.begin()+i*bs+bs, x) - (B.begin()+i*bs);
      }
      return n;
   }

   T findKth(ll L, ll R, ll K){
      K++;
      ll ok = LINF;
      ll ng = -LINF;
      while(abs(ok-ng)>1){
         ll mid = (ok+ng)/2;
         if(count(L,R,mid)>=K) ok = mid;
         else ng = mid;
      }
      return ok;
   }

   T findKth2(ll L, ll R, ll K){
      K++;
      ll ok = N-1;
      ll ng = -1;
      while(abs(ok-ng)>1){
         ll mid = (ok+ng)/2;
         if(count(L,R,C[mid])>=K) ok = mid;
         else ng = mid;
      }
      return C[ok];
   }

   vector<T> A,B;//A:raw data  B:backet
   vector<T> C;//sorted entire data
   ll bs = 1;
   ll N = 1;
};