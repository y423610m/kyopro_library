#pragma once

struct LCP{

    vector<vector<int>> dp;
    LCP(const string& S, const string& T):
    dp(S.size()+1, vector<int>(T.size()+1, 0))
    {
        for(int i=S.size()-1;i>=0;i--){
            for(int j=T.size()-1;j>=0;j--){
                if(S[i]==T[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = 0;
            }
        }
    }

    vector<int>& operator[](int i){
        return dp[i];
    }

    /*
        string S = "abc";
        string T = "abdabc";
        LCP lcp(S,T);
        lcp[i][j]:=S[i],T[j]からの最長共通連続部分列
        rep(i,S.size()) EL(lcp[i])
    */
};