#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

//mod
const int MOD = 998244353;
//const int MOD = 1000000007;
//iteration
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
//output
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
//pair
#define FI first
#define SE second
//constants
#define INF 1001001001;
#define LINF 1001001001001001001LL;


using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using P = pair<int, int>;
using mint = atcoder::static_modint<MOD>;


template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    	os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}


ostream &operator<<(ostream &os, const mint x) {
    os<<x.val();
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}



template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

int h,w;
int ans = 0;
int cnt = 0;
V<string> C;
int sx, sy;
V<string> gone;
void dfs(int x, int y, int d){
    rep(i,4){
        int nx = x + DX[i];
        int ny = y + DY[i];
        if(0<=nx&&nx<h&&0<=ny&&ny<w&&C[nx][ny]!='#'){
            cnt++;

            if(nx==sx&&ny==sy){
                //start に　戻ってきた
                if(d+1>ans){
                    ans = d+1;
                    gone = C;
                }
            }
            else{
                C[nx][ny] = '#';
                dfs(nx, ny, d+1);
                C[nx][ny] = '.';
            }
        }
    }
}


void solve() {
    cin>>h>>w;
    C.resize(h);
    cin>>C;
    gone = C;

    ll cnt = 0;

    for(sx=0;sx<h;sx++){
        for(sy=0;sy<w;sy++){
            if(C[sx][sy]!='#'){// && gone[sx][sy]!='#'){
                dfs(sx, sy, 0);
            }
        }
    }

    if(ans<=3) ans = -1;
    PL(ans)
    EL(cnt)


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
