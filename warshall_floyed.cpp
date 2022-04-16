#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30-1;

struct warshall_floyed{

	int N;
	vector<vector<int>> dist;


	warshall_floyed(int n){
		N = n;
		dist.resize(n, vector<int>(n, INF));
		for(int i=0;i<n;i++) dist[i][i] = 0;
	}

	void set_graph(int m){
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v;
			u--,v--;
			w = 1;
			cin>>w;
			dist[u][v] = w;
			dist[v][u] = w;
		}
	}

	void solve(){
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
	}
};

int main(){
	int n, m;
	cin>>n>>m;

	warshall_floyed wf(n);
	wf.set_graph(m);
	wf.solve();
	cout<<1<<endl;
    vector<vector<int>>& ans = wf.dist;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}