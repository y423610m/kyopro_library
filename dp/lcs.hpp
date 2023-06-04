

template<typename T>
struct LCS{
    int len = 0;
    vector<int> idS, idT;
    T lcs;
    LCS(const T& s, const T& t){
        int N = s.size();
        int M = t.size();
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        rep(i,N) rep(j,M){
            chmax(dp[i+1][j+1], dp[i][j+1]);
            chmax(dp[i+1][j+1], dp[i+1][j]);
            if(s[i]==t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
        }
        len = dp[N][M];

        //復元
        int i=N-1;
        int j=M-1;
        while(i>=0&&j>=0){
            if(s[i]==t[j]){
                lcs.push_back(s[i]);
                idS.emplace_back(i);
                idT.emplace_back(j);
                i--, j--;
            }
            else if(dp[i][j+1]<dp[i+1][j]) j--;
            else i--;
        }

        reverse(idS.begin(), idS.end());
        reverse(idT.begin(), idT.end());
        reverse(lcs.begin(), lcs.end());
    }

    /*
        string s,t;
        //vector<int> s,t; cin>>s>>t;
        cin>>s>>t;
        LCS lcs(s,t);
        EL(lcs.len)//長さ
        EL(lcs.idS)//id
        EL(lcs.idT)
        EL(lcs.lcs)//一例
        //EDPC F
    */
};



