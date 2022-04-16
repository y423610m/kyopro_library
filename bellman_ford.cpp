#include <bits/stdc++.h>
using namespace std;

const int INF = (1<<30)-1;

struct bellman_ford{
	struct edge{
		int from, to, cost;
	};

	int N;
	vector<int> dist;
	vector<edge> edges;
	bool _has_minus_loop = false;


	bellman_ford(int n){
		N = n;
		dist.resize(n,INF);
	}

	void set_graph(int m){
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v;
			u--; v--;
			w=1;
			cin>>w;
			edges.push_back({u,v,w});
		}
	}

	void solve(int s){
		dist[s] = 0;
		int cnt = 0;
		while(true){
			bool updated = false;
			for(int i=0;i<edges.size();i++){
				edge e = edges[i];
				if(dist[e.from]!=INF && dist[e.from]+e.cost<dist[e.to]){
					dist[e.to] = dist[e.from]+e.cost;
					updated = true;
				}
			}
			if(!updated) break;
			cnt++;
			if(cnt>edges.size()){
				cout<<"minus closed"<<endl;
				_has_minus_loop = true;
				break;
			}
		}
	}
};

int main(){

	int n,m;
	cin>>n>>m;

	bellman_ford bf(n);
	bf.set_graph(m);
	bf.solve(0);
	bool has_minus_loop = bf._has_minus_loop;
	vector<int>& ans = bf.dist;
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<endl;

}