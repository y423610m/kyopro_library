#pragma once

struct EditDistance{

   vector<vector<ll>> dp;
   vector<vector<array<int,3>>> from;
   ll N, M;

   ll solve(string& S, string& T, ll INSERT_COST=1, ll DELETE_COST=1, ll CHANGE_COST=1){
      N = S.size();
      M = T.size();      
      //高々max(N,M)で可能なはずなので，ちょっと大きめにしておく．
      dp = vector<vector<ll>>(N+1, vector<ll>(M+1, (N+M)*2));
      from = vector<vector<array<int, 3>>>(N+1, vector<array<int, 3>>(M+1));
      for(int i=0; i<=N; i++) dp[i][0] = INSERT_COST*i;
      for(int j=0; j<=M; j++) dp[0][j] = INSERT_COST*j;

      for(int i=1; i<=N; i++){
         for(int j=1; j<=M; j++){
            if(S[i-1]==T[j-1]){
               dp[i][j] = dp[i-1][j-1];
               from[i][j] = {i-1,j-1,0};
            }
            ll D = dp[i-1][j] + DELETE_COST;
            if(dp[i][j]>D){
               dp[i][j] = D;
               from[i][j] = {i-1, j, 1};
            }
            ll I = dp[i][j-1] + INSERT_COST;
            if(dp[i][j]>I){
               dp[i][j] = I;
               from[i][j] = {i, j-1, 2};
            }
            ll C = dp[i-1][j-1] + CHANGE_COST;
            if(dp[i][j]>C){
               dp[i][j] = C;
               from[i][j] = {i-1, j-1, 3};
            }
         }
      }
      return dp[N][M];
   }

   vector<array<int, 3>> recovery(){
      vector<array<int, 3>> ret;
      ll n = N;
      ll m = M;
      ll op = 0;
      while(n!=0&&m!=0){
         if(from[n][m][2]>0) ret.push_back(from[n][m]);
         auto [nn, nm, nop] = from[n][m];
         n = nn;
         m = nm;
         op = nop;
      }
      reverse(ret.begin(), ret.end());
      return ret;
   }
};

/*
   string S = "abc", T = "abcd";
   EditDistance ed;
   int dist = ed.solve(S,T);
   int dist = ed.solve(S,T,INSERT_COST, DELETE_COST, CHANGE_COST);
   vector<array<int,3>> op = ed.recovery();
   // {Sの操作文字，Tの操作文字，操作番号}がdist個
   1:削除 2:挿入 3:変更
   https://o-treetree.hatenablog.com/entry/DPL1E
*/