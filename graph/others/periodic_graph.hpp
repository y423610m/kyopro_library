#pragma once
#include "graph/graph_template.hpp"

/*
機能

- 頂点iからn回移動した先 O(logN)
   閉路につくまではダブリング
   その後は周期で求める
      最初に閉路につく時間とその頂点覚える
- 頂点iからjにたどり着けるか
- 頂点iとjの最近到達地点
*/

template<typename CostT>
struct PeriodicGraph{
   int N;
   PeriodicGraph()
   {}

   vector<pair<int, int>> loopIdx;//[頂点iが属する閉路のid,閉路内id].属さないなら-1
   vector<vector<int>> loops;//実際に要素格納.[i][j]:=i番目のループのj番目の頂点
   vector<pair<int,CostT>> nearestLoop;//{最近ループ上頂点, そこまでの距離}
   void build(int N, const Graph<CostT>& G, const Graph<CostT>& inG){
      //まずは閉路列挙
      vector<int> in(N);
      for(int i=0;i<N;i++){
         for(const auto& e:G[i]){
            in[e.to]++;
         }
      }
      queue<int> que;
      for(int i=0;i<N;i++) if(in[i]==0) que.push(i);
      while(!que.empty()){
         int p = que.front(); que.pop();
         for(const auto& e:G[p]){
            in[e.to]--;
            if(in[e.to]==0) que.push(e.to);
         }
      }

      loopIdx.resize(N, {-1, -1});
      nearestLoop.resize(N, {-1, -1});//nearestNode, distance
      for(int i=0;i<N;i++) if(in[i]){
         assert(in[i]==1);
         in[i]--;
         loops.resize(loops.size()+1);
         loops.back().push_back(i);
         nearestLoop[i] = {i, 0};
         loopIdx[i] = {int(loops.size())-1, int(loops.back().size())-1};
         que.push(i);
         while(!que.empty()){
            int p = que.front(); que.pop();
            for(const auto& e:G[p]) if(in[e.to]){
               in[e.to]--;
               loops.back().push_back(e.to);
               nearestLoop[e.to] = {e.to, 0};
               loopIdx[e.to] = {int(loops.size())-1, int(loops.back().size())-1};
               que.push(e.to);
               break;
            }
         }
      }
      
      for(int i=0;i<N;i++) assert(in[i]==0);

      //最近距離探す
      for(int i=0;i<N;i++) if(nearestLoop[i].second==0) que.push(i);
      //閉路から離れながら更新
      while(!que.empty()){
         int p = que.front(); que.pop();
         for(const auto& e: inG[p]) if(nearestLoop[e.to].second==-1) {
            nearestLoop[e.to] = {nearestLoop[p].first, nearestLoop[p].second+1};
            que.push(e.to);
         }
      }
      //DEBUG
      rep(i,N){
         ES(i) ES(loopIdx[i]) EL(nearestLoop[i])
      }
      rep(i,loops.size()){
         EL(loops[i])
      }

      ll M = 64;
      // while(M<=N) M <<=1;
      db.resize(M, vector<CostT>(N));
      rep(i,N) db[0][i] = G[i][0].to;
      EL(db[0])
      rep(i,M-1){
         rep(j,N) db[i+1][j] = db[i][db[i][j]];
         // EL(db[i+1])
      }
   }

   int Proceed(int p, ll K){
      return _Proceed(p, K);
      // if(K==0) return p;
      // else if(nearestLoop[p].second < K) return _Proceed(p, K);
      // else{
      //    K -= nearestLoop[p].second;
      //    p = nearestLoop[p].first;
      //    auto [i, j] = loopIdx[p];
      //    K %= loops[i].size();
      //    p = loops[i][(j+K)%loops[i].size()];
      // }
      // return p;
   }

   vector<vector<CostT>> db;
   int _Proceed(int p, ll K){
      for(int i=0;i<64;i++){
         if(K&1) {
            p = db[i][p];
         }
         K >>= 1;
         if(K==0) break;
      }
      return p;
   }

   CostT CanReach(int from, int to){
      return -1;
   }

   bool IsOnLoop(int p){
      return loopIdx[p].first>=0;
   }

   int GetGoalId(int x){
      return -1;
   }
};

/*
ac167d
*/