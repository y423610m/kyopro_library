#pragma once


/*
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
60!=82桁<512bit
kth_element<boost::multiprecision::int1024_t>(string(A,'a')+string(B,'b'), K-1)
*/

template<typename U>
string kth_element(string& S, U K){
    K++;
    ll N = S.size();
    vector<U> fact_(N+1);
    fact_[0] = 1;
    for(int i=0;i<N;i++) fact_[i+1] = fact_[i] * (i+1);
    string ans;
    map<char,ll> mp;
    for(auto c:S) mp[c]++;
    U comb = fact_[N];
    for(auto& [c,n]:mp) comb /= fact_[n];
    if(comb<K) return ans;
    for(int i=0;i<N;i++){
        for(auto& [c,n]:mp){
            auto tmp = comb*n/(N-i);
            if(tmp<K) K -= tmp;
            else{
                comb = comb*n/(N-i);
                ans.push_back(c);
                if(n==1) mp.erase(c);
                else mp[c]--;
                break;
            }
        }
    }
    return ans;
}

template<typename U>
string kth_element(string&& S, U K){
    K++;
    ll N = S.size();
    vector<U> fact_(N+1);
    fact_[0] = 1;
    for(int i=0;i<N;i++) fact_[i+1] = fact_[i] * (i+1);
    string ans;
    map<char,ll> mp;
    for(auto c:S) mp[c]++;
    U comb = fact_[N];
    for(auto& [c,n]:mp) comb /= fact_[n];
    if(comb<K) return ans;
    for(int i=0;i<N;i++){
        for(auto& [c,n]:mp){
            auto tmp = comb*n/(N-i);
            if(tmp<K) K -= tmp;
            else{
                comb = comb*n/(N-i);
                ans.push_back(c);
                if(n==1) mp.erase(c);
                else mp[c]--;
                break;
            }
        }
    }
    return ans;
}

template<typename U, typename T>
vector<T> kth_element(vector<T>& S, U K){
    K++;
    ll N = S.size();
    vector<U> fact_(N+1);
    fact_[0] = 1;
    for(int i=0;i<N;i++) fact_[i+1] = fact_[i] * (i+1);
    vector<T> ans;
    map<char,ll> mp;
    for(auto c:S) mp[c]++;
    U comb = fact_[N];
    for(auto& [c,n]:mp) comb /= fact_[n];
    if(comb<K) return ans;
    for(int i=0;i<N;i++){
        for(auto& [c,n]:mp){
            auto tmp = comb*n/(N-i);
            if(tmp<K) K -= tmp;
            else{
                comb = comb*n/(N-i);
                ans.push_back(c);
                if(n==1) mp.erase(c);
                else mp[c]--;
                break;
            }
        }
    }
    return ans;
}

template<typename U, typename T>
vector<T> kth_element(vector<T>&& S, U K){
    K++;
    ll N = S.size();
    vector<U> fact_(N+1);
    fact_[0] = 1;
    for(int i=0;i<N;i++) fact_[i+1] = fact_[i] * (i+1);
    vector<T> ans;
    map<char,ll> mp;
    for(auto c:S) mp[c]++;
    U comb = fact_[N];
    for(auto& [c,n]:mp) comb /= fact_[n];
    if(comb<K) return ans;
    for(int i=0;i<N;i++){
        for(auto& [c,n]:mp){
            auto tmp = comb*n/(N-i);
            if(tmp<K) K -= tmp;
            else{
                comb = comb*n/(N-i);
                ans.push_back(c);
                if(n==1) mp.erase(c);
                else mp[c]--;
                break;
            }
        }
    }
    return ans;
}