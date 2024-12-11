#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;
// #define _GLIBCXX_DEQUE_BUF_SIZE 512
// #pragma comment(linker, "/stack:1000000000")


//mint


// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
string Yes = "Yes";
string No = "No";
const char* NY[] = {"No", "Yes"};

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
// #define ONLINE_JUDGE 1
#ifdef ONLINE_JUDGE
   #define ES(a) while(0){}
   #define EL(a) while(0){}
#else
   #define NAME(a) #a
   #define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
   #define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
#endif
#define END(a) {PL(a) return;}
#define RES(a) cerr<<"\r"<<NAME(a)<<": "<<(a)<<"   ";
#define fi first
#define se second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using Pii = pair<int, int>;
using Tiii = tuple<int, int, int>;
using Tiiii = tuple<int, int, int, int>;
using Pll = pair<ll,ll>;
using Tlll = tuple<ll,ll,ll>;
using Tllll = tuple<ll,ll,ll,ll>;
template<typename T> using V = vector<T>;
template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T, unsigned long int sz> using Ar = array< T , sz >;
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, typename U> void operator--(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator--(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, typename U> void operator++(pair<T, U>& p){p.first++, p.second++;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first++, p.second++;}//post
template<class T,class U> struct std::hash<std::pair<T,U>>{size_t operator()(const std::pair<T,U> &p) const noexcept {return (std::hash<T>()(p.first)+1) ^ (std::hash<U>()(p.second)>>2);}};
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream&, const std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream& os, const std::tuple<T...>& tup){if (n != 0){os << " ";} os << std::get<n>(tup); print_tuple<n+1>(os, tup);}
template <typename... T> std::ostream& operator<<(std::ostream& os, const std::tuple<T...>& tup) {print_tuple<0>(os, tup); return os;}
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>& tup){is>> std::get<n>(tup); input_tuple<n+1>(is, tup);}
template <typename... T> std::istream& operator>>(std::istream& is, std::tuple<T...>& tup) {input_tuple<0>(is, tup); return is;}
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> bool chmin(T& t, const U& u) {if (t > u){t = u; return true;} return false;}
template<typename T, typename U> bool chmax(T& t, const U& u) {if (t < u){t = u; return true;} return false;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

// #include "sparse_table2d.hpp"

// using DGGINT = int;

#define endl "\n"

template <typename T>
void Print2D(const V<T>& matrix, int H, int W)
{
    cout << "------" << endl;
    rep(h,H){
        rep(w,W){
            cout<<matrix[h*W+w]<<" ";
        }
        cout<<endl;
    }
}


void solve() {

    ll H,W;
    cin>>H>>W;
    std::vector<int> depthMatrix(H*W);
    iota(ALL(depthMatrix), 0);
    std::vector<int> original = depthMatrix;

    const int intLogH = int(log2(H+1));
    const int intLogW = int(log2(W+1));

    std::vector<std::vector<std::vector<int>>> matrixCache(intLogH+1, std::vector<std::vector<int>>(intLogW+1, std::vector<int>(H*W, -1)));
    matrixCache[0][0] = depthMatrix;

    //build matrixCache[0]
    for(int h=0; h<H; h++){
        for(int logW=1; logW<=intLogW; logW++){
            for(int w=0; w+(1<<(logW))<=W; w++){
                matrixCache[0][logW][h*W+w] = std::max(matrixCache[0][logW-1][h*W+w], matrixCache[0][logW-1][h*W+w+(1<<(logW-1))]);
            }
        }
    }

    for(int logH=1; logH<=intLogH; logH++){
        for(int h=0; h+(1<<logH)<=H; h++){
            for(int w=0; w<W; w++){
                matrixCache[logH][0][h*W+w] = std::max(matrixCache[logH-1][0][h*W+w], matrixCache[logH-1][0][(h+(1<<(logH-1)))*W+w]);
            }
            for(int logW=1; logW<=intLogW; logW++){
                for(int w=0; w+(1<<logW)<=W; w++){
                    matrixCache[logH][logW][h*W+w] = std::max(matrixCache[logH][logW-1][h*W+w], matrixCache[logH][logW-1][h*W+w+(1<<(logW-1))]);
                }
            }
        }
    }

    auto Get = [&](int mh, int mw, int Mh, int Mw, int e=-1)-> int {
        if(mh==Mh) return e;
        if(mw==Mw) return e;

        const int logH = max(0, int(log2(Mh-mh)));
        const int logW = max(0, int(log2(Mw-mw)));

        // ES(logH) EL(logW)

        // Print2D(matrixCache[logH][logW], H, W);

        return std::max(
            std::max(matrixCache[logH][logW][mh*W             + mw], matrixCache[logH][logW][mh*W             + Mw-(1<<logW)]),
            std::max(matrixCache[logH][logW][(Mh-(1<<logH))*W + mw], matrixCache[logH][logW][(Mh-(1<<logH))*W + Mw-(1<<logW)])
            );
    };

    int Q; cin>>Q;
    rep(q,Q){
        int mh, mw, Mh, Mw;
        cin>>mh>>mw>>Mh>>Mw;
        PL(Get(mh, mw, Mh, Mw))
    }

    rep(i,100){
        int mh=rand()%H;
        int Mh=rand()%H;
        int mw=rand()%W;
        int Mw=rand()%W;
        if(mh>Mh) swap(mh, Mh);
        if(mw>Mw) swap(mw, Mw);
        int ans = -1;
        repi(h,mh,Mh)
        repi(w,mw,Mw)
        chmax(ans, original[h*H+w]);

        if(ans!=Get(mh, mw, Mh, Mw)){
            ES(mh) ES(mw) ES(Mh) EL(Mw)
        }
    }
    EL("END")

    if(0){
        rep(h, matrixCache.size()){
            rep(w,matrixCache[h].size()){
                ES(h) EL(w)
                Print2D(matrixCache[h][w], H, W);
            }
        }
    }

    

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++){
      // cout << "Case #" << (tt+1) << ": ";//MHC
      solve();
   }
   return 0;
}
