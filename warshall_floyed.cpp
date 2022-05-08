#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30-1;
using ll = long long;
ll MOD = 1'000'000'007LL;

struct warshall_floyed{

	int N_;
	vector<vector<int>> dist;

	//経路復元用
	vector<int> path;
	vector<vector<pair<int,int>>> G;
	vector<vector<ll>> cnt;

	warshall_floyed(int n_){
		N_ = n_;
		G.resize(N_);

		//NOTE warshall floyedは全始点だからリセット不要．ここでdistのサイズ決定する
		dist.resize(N_, vector<int>(N_, INF));
		for(int i=0;i<N_;i++) dist[i][i] = 0;
		cnt.resize(N_, vector<ll>(N_,0));
		for(int i=0;i<N_;i++) cnt[i][i] = 1;
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
			dist[u][v] = w;
			dist[v][u] = w;
			//経路復元はu,v逆!!!
			G[u].push_back({v,w});
			G[v].push_back({u,w});

			cnt[u][v] = 1;
			cnt[v][u] = 1;
		}
	cout<<"aaa"<<endl;

	}

	void reset_dist(){
		dist.resize(N_, vector<int>(N_, INF));
		for(int i=0;i<N_;i++) dist[i][i] = 0;
	}

	void solve(){




		for(int k=0;k<N_;k++){
			for(int i=0;i<N_;i++){
				for(int j=0;j<N_;j++){

					//dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
					if(dist[i][j] > dist[i][k]+dist[k][j]){
						dist[i][j] = dist[i][k]+dist[k][j];
						cnt[i][j] = (cnt[i][k]%MOD) * (cnt[k][j]%MOD);
						cnt[i][j] %= MOD;
					}
					else if(dist[i][j] == dist[i][k]+dist[k][j]){
						cnt[i][j] += (cnt[i][k]%MOD) * (cnt[k][j]%MOD) % MOD;
						cnt[i][j] %= MOD;
					}

				}
			}
		}
	}

	void find_path(int s, int g){
		if(dist[s][g]==INF) return;
		int p = g;
		path.clear();
		path.push_back(p);
		while(p!=s){
			for(auto [to,w]:G[p]){
				if(dist[s][to]+w==dist[s][p]){
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
	int n, m;
	cin>>n>>m;
	int start = 0;
	int goal = n-1;

	warshall_floyed wf(n);
	wf.set_graph(m, false);
	wf.solve();

	//各点間距離
    vector<vector<int>>& ans = wf.dist;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	//経路復元
	wf.find_path(start, goal);
	vector<int>& path = wf.path;
	for(auto p: path) cout<<p<<" ";
	cout<<endl;

	//何通りの行き方あるか
	vector<vector<ll>> cnt = wf.cnt;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<cnt[i][j]<<" ";
		}
		cout<<endl;
	}

}