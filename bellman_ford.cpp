#include <bits/stdc++.h>
using namespace std;

const int INF = (1<<30)-1;

struct bellman_ford{
	struct edge{
		int from, to, cost;
	};

	int N_;
	int s;
	vector<int> dist;
	vector<edge> edges;
	bool _has_minus_loop = false;
	vector<int> path;
	vector<vector<pair<int,int>>> G;


	bellman_ford(int n_){
		N_ = n_;
		G.resize(N_);
	}

	void set_graph(int m, bool cinW = false){
		if(cinW) cerr<<"cin>>w enabled"<<endl;
		else cerr<<"cin>>w not enabled"<<endl;

		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v;
			u--; v--;
			w=1;
			if(cinW) cin>>w;
			edges.push_back({u,v,w});
			//経路復元用なので逆!!!
			G[v].push_back({u,w});
		}
	}

	void solve(int s_){
		s = s_;
		dist.resize(N_,INF);
		dist[s] = 0;

		int cnt_loop = 0;
		while(true){
			bool updated = false;
			for(int i=0;i<edges.size();i++){
				edge e = edges[i];
				if(dist[e.from]+e.cost<dist[e.to]){
					dist[e.to] = dist[e.from]+e.cost;
					updated = true;
				}
			}
			if(!updated) break;
			cnt_loop++;
			if(cnt_loop>edges.size()){
				cout<<"minus closed"<<endl;
				_has_minus_loop = true;
				break;
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
	cin>>n>>m;
	int start = 0;
	int goal = n-1;

	bellman_ford bf(n);
	bf.set_graph(m, false);
	bf.solve(start);

	//負閉路確認
	if(bf._has_minus_loop) cout<<"G has minus closed loop"<<endl;

	//最短距離
	vector<int>& ans = bf.dist;
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<endl;

	//経路復元
	bf.find_path(goal);
	vector<int>& path = bf.path;
	for(auto p: path) cout<<p<<" ";
	cout<<endl;

}