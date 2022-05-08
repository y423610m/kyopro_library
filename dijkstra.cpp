#include<bits/stdc++.h>
using namespace std;

const int INF = (1<<30)-1;
const long long int MOD = 1'000'000'007LL;

struct dijkstra{

	using P = pair<int, int>;
	int N_;
	int s;
	vector<int> dist;
	vector<vector<P>> G;
	vector<int> path;
	vector<long long> cnt; 

	dijkstra(int n_){
		N_ = n_;
		G.resize(N_);
	}

	void set_graph(int m, bool cinW = false){
		if(cinW) cerr<<"cin>>w enabled"<<endl;
		else cerr<<"cin>>w not enabled"<<endl;

		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v;
			u--,v--;
			w = 1;
			if(cinW) cin>>w;
			//経路復元はu,v逆!!!
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
	}
	
	void set_graph(const vector<vector<P>>& G_){
		G = G_;
	}

	void reset_dist(){
		dist.resize(N_, INF);
	}

	void solve(int s_){
		s = s_;

		dist.resize(N_, INF);
		for(auto& d:dist) d=INF;
		cnt.resize(N_);
		for(auto& c:cnt) c=0;

		dist[s] = 0;
		cnt[s] = 1;
		priority_queue<P,vector<P>,greater<P>> que;//dist, to
		que.push({0,s});

		while(!que.empty()){
			int d = que.top().first;
			int now = que.top().second;
			que.pop();
			if(d>dist[now]) continue;
			for(int i=0;i<G[now].size();i++){
				int to = G[now][i].first;
				int w = G[now][i].second;
				if(dist[now]+w<dist[to]){
					dist[to] = dist[now] + w;
					que.push({dist[to], to});
					cnt[to] = cnt[now];
				}
				else if(dist[now]+w==dist[to]){
					cnt[to] += cnt[now];
					cnt[to] %= MOD;
				}
			}
		}
	}


	void find_path(int g){
		if(dist[g]==INF) return;
		int p = g;
		path.clear();
		path.push_back(p);
		while(p!=s){
			for(auto [to,w]:G[p]){
				if(dist[to]+w==dist[p]){
					path.push_back(to);
					p = to;
					break;
				}
			}
		}
		reverse(path.begin(), path.end());
	}
	

};


int main(){

	int n,m;
	cin>>n;
	cin>>m;
	int start = 0;
	int goal = n-1;
	//m = n-1;

	dijkstra di(n);
	di.set_graph(m, false);
	di.solve(start);

	//start始点からの最短経路
	vector<int>& ans = di.dist;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
	cout<<endl;

	//経路復元
	di.find_path(goal);
	vector<int>& path = di.path;
	for(auto p:path) cout<<p<<" ";
	cout<<endl;
	cout<<endl;

	//最短経路何通りある?
	vector<long long>& cnt = di.cnt;
	for(auto c:cnt) cout<<c<<" ";
	cout<<endl;


}