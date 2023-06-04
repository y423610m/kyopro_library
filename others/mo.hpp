#pragma once

struct Mo{
    ll N;
    vector<pair<ll,ll>> LR;
    Mo(ll N):N(N){}

    void query(ll l, ll r){
        LR.emplace_back(l, r);
    }

    template< typename AL, typename AR, typename EL, typename ER, typename O >
    void solve(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
        ll Q = (ll) LR.size();
        // ll bs = N / max(1LL, min< ll >(N, sqrt(Q)));
        ll bs = N / min< ll >(N, sqrt(Q));
        
        //bs = sqrt(Q); chmax(bs, 1);
        vector< ll > ord(Q);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](ll a, ll b) {
            if(LR[a].first/bs!=LR[b].first/bs) return LR[a].first/bs<LR[b].first/bs;
            return ((LR[a].first/bs) & 1) ? LR[a].second > LR[b].second : LR[a].second < LR[b].second;
        });
        ll l = 0, r = 0;
        for(auto idx : ord) {
            while(l > LR[idx].first) add_left(--l);
            while(r < LR[idx].second) add_right(r++);
            while(l < LR[idx].first) erase_left(l++);
            while(r > LR[idx].second) erase_right(--r);
            out(idx);
        }
    }

    template< typename A, typename E, typename O >
    void solve(const A &add, const E &erase, const O &out) {
        solve(add, add, erase, erase, out);
    }
};
