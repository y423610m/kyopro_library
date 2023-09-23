#pragma once

struct CompleteBinaryTree{

   void SetN(long long _n){
      n = _n;
   }

   void SetDepth(long long d){
      depth = d;
      for(int i=0;i<d;i++){
         n += 1LL << i;
      }
   }

   long long CountDescendantsDist(long long p, long long dist, bool right){
      if(dist==0) return 0;
      ll l = p;
      rep(i,dist){
         l <<= 1;
         if(l>n) return 0;
      }
      if(right){
         for(int i=1;i<=(dist-1);i++) if(l+(1LL<<i)>n) return 0;
         l += 1LL<<(dist-1);
      }

      bool ok = true;
      for(int i=1;i<=(dist-1);i++) if((l-1+(1LL<<i))>n) ok = false;
      ll r = l ;
      if(ok) r += (1LL<<(dist-1)) -1;
      else r = n;

      if(l<=n) return r - l + 1;
      return 0;
   }

   long long CountDist(long long p, long long dist){
      if(dist<0) return 0;
      if(dist==0) return 1;
      long long count = CountDescendantsDist(p, dist, false) + CountDescendantsDist(p, dist, true);
      while(true){
         if(p==1) break;
         long long parent = p/2;
         dist--;
         
         if(dist==0){
            count++;
            break;
         }
         //p is left
         if(p%2==0) count += CountDescendantsDist(parent, dist, true);
         else count += CountDescendantsDist(parent, dist, false);
         p = parent;
      }
      return count;
   }

   long long CountDescendants(long long p){
      long long ret = 0;
      for(long long d=1;;d++){
         long long descendants = CountDist(p, d);
         if(descendants==0) return ret;
         else ret += descendants;
      }
   }

   long long GetDist(long long a, long long b){
      ll dist = 0;
      auto [depthA, posA] = GetPosition(a);
      auto [depthB, posB] = GetPosition(b);
      while(depthA>depthB){
         depthA--;
         a >>= 1;
         dist++;
      }
      while(depthA<depthB){
         depthB--;
         b >>= 1;
         dist++;
      }
      while(a!=b){
         a >>= 1;
         b >>= 1;
         dist+=2;
      }
      return dist;
   }

   //depth, i := 0-index
   long long GetIndex(int depth, long long i){
      long long left = 1LL << (depth);
      if(left<=i) return -1;
      return left + i;
   }

   pair<long long, long long> GetPosition(long long p){
      ll d = __builtin_ffsll(p)-1;
      d = 63 - __builtin_clzll(p);
      p -= 1LL<<(d);
      return {d, p};
   }

   long long n = 1LL<<63;
   long long depth = 63;
};