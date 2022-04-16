#include<bits/stdc++.h>
using namespace std;

const int INF = (1<<30)-1;

struct dijkstra{

	using P = pair<int, int>;

	vector<int> dist;
	vector<vector<P>> G;

	dijkstra(int n){
		dist.resize(n, INF);
		G.resize(n);
	}

	void set_graph(int m){
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v;
			u--,v--;
			w = 1;
			cin>>w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
	}

	
	void set_graph(const vector<vector<P>>& G_){
		G = G_;
	}

	void reset_dist(){
		for(int i=0;i<dist.size();i++) dist[i] = INF;
	}

	void solve(int s){
		dist[s] = 0;
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
				}
			}
		}
	}
	

};


int main(){

	int n,m;
	cin>>n;
	cin>>m;
	//m = n-1;
	dijkstra di(n);
	di.set_graph(m);
	di.solve(0);
	vector<int> ans = di.dist;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
}