#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

template <long long mod_, std::enable_if_t<(1 <= mod_)>* = nullptr>
struct static_modint{
    using ll = long long;
    ll v=0;
    ll mod;
    static_modint(){
        mod = mod_; 
    }
    static_modint(ll x){
        v = x; 
        mod = mod_; 
        v %= mod;
    }
    void operator=(ll x){v = x; v %= mod;}
    bool operator==(ll x){return v==x;}
    ll operator+(ll x){return (v+x)%mod;}
    ll operator+(static_modint x){return (v+x.v%mod)%mod;}
    ll operator+=(ll x){v += x; v %= mod; return v;}
    ll operator+=(static_modint x){v += x.v; v %= mod; return v;}
    ll operator++(int){v += 1; v %= mod; return v;}
    ll operator-(ll x){x = v-x; while(x<0){x += mod;} return x;}
    ll operator-(static_modint x){x.v -= v; while(x.v<0){x.v += mod;} return x.v;}
    ll operator-=(ll x){v -= x; if(v<0) {v += mod;} return v;}
    ll operator-=(static_modint x){v -= x.v; if(v<0){v += mod;} return v;}
    ll operator--(int){v -= 1; if(v<0) v+=mod; return v;}
    ll operator*(ll x){x %= mod; x*=v; x %= mod; return x;}
    ll operator*(static_modint x){x.v %= mod; x.v *= v; x.v %= mod; return x.v;}
    ll operator*=(ll x){x %= mod; v *= x; v %= mod; return v;}
    ll operator*=(static_modint x){x.v %= mod; v *= x.v; v %= mod; return v;}
    ll operator/(ll x){if(v>=x && v%x==0){ return v/x;} ll inv_ = inv(x)%mod; return (v*inv_)%mod;}
    ll operator/(static_modint x){if(v>=x.v && v%x.v==0){ return v/x.v;} ll inv_ = inv(x.v)%mod; return (v*inv_)%mod;}
    ll operator/=(ll x){if(v>=x && v%x==0){ v /= x; return v;} ll inv_ = inv(x); v *= inv_; v %= mod; return v;}
    ll operator/=(static_modint x){if(v>=x.v && v%x.v==0){ v /= x.v; return v;} ll inv_ = inv(x.v); v *= inv_; v %= mod; return v;}
    ll inv(ll x){
        ll m = mod-2;
        ll result = 1;
        ll tmp = x%mod;
        while(m){
            if(m&1) result *= tmp;
            result %= mod;
            tmp = tmp*tmp;
            tmp %= mod;
            m /= 2;
        }
        return result;
    }
    ll val()const{
        return v;
    }
};

using mint = static_modint<MOD>;


ostream &operator<<(ostream &os, const mint x){
    os<< x.val();
    return os;
}

int main(){
    mint a = 10;
    mint b = 1000;
    mint c=1;

    cout<<a<<endl;
    cout<<a+10<<endl;
    cout<<a+b<<endl;
    cout<<a-10<<endl;
    cout<<a-b<<endl;
    cout<<a*10<<endl;
    cout<<a*b<<endl;
    cout<<a/10<<endl;
    cout<<a/b<<endl;    
    
    a += 10;
    b *= 2;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c/8<<endl;

    return 0;
}