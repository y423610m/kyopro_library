#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

const int MOD = 998244353;
//const int MOD = 1000000007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using mint = atcoder::static_modint<MOD>;

template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}

template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;

vector<string> SEPARATE(string s_in, string split=","){ vector<string> vs;	string tmp; for(int i=0;i<s_in.size();i++){	bool found = false;		for(int j=0;j<split.size();j++){ if(s_in[i]==split[j]){	if(tmp!=""){vs.push_back(tmp);} tmp = ""; found = true; break; }}	if(!found) tmp+=s_in[i];	} 	if(tmp!="") vs.push_back(tmp);	return vs;}
ll POW(ll a, ll b){	ll ret = 1;	ll tmp = a;	while(b){if(b&1){ret *= tmp;} b /= 2; tmp *= tmp;}	return ret;}
vector<ll> DIGIT(ll a, int b=2){vector<ll> ret;while(a){ret.push_back(a%b); a/=b; }reverse(ret.begin(), ret.end());return ret;}

int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};


void solve() {



	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve();

	return 0;
}
