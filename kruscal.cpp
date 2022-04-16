#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = long long int;

struct kruscal{
	struct edge{
		int cost, from, to, used, id;
		bool operator <(edge& a){return(this->cost<a.cost);}
	};

	int N;
	ll sum;
	vector<edge> edges;

	kruscal(int n){
		N = n;
	}

	void set_graph(int m){
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v;
			w = 1;
			cin>>w;
			u--; v--;
			edges.push_back({w,u,v,0,i});
		}
	}

	void solve(){
		sort(edges.begin(), edges.end());
		dsu DSU(N);
		vector<bool> used(edges.size());
		int cnt = 0;
		sum = 0;
		for(int i=0;i<edges.size();i++){
			edge e = edges[i];
			if(!DSU.same(e.from, e.to)){
				DSU.merge(e.from, e.to);
				sum += e.cost;
				edges[i].used = 1;
				cnt++;
			}
			if(cnt+1==N){
				break;
			}
		}

		sort(edges.begin(), edges.end(), [](edge a, edge b){
			return (a.id<b.id);
		});
	}
};

int main(){
	int n,m;
	cin>>n>>m;

	kruscal kr(n);
	kr.set_graph(m);
	kr.solve();
	auto& ans = kr.edges;
	for(int i=0;i<ans.size();i++) cout<<ans[i].used<<" ";
	cout<<endl;
	ll sum = kr.sum;
	cout<<sum<<endl;

}