#pragma once

#include "../graph_template.hpp"

template<typename T = int, typename U = int>//cost type
struct BFS{

	int N;
	vector< T > dist;
	vector< U > cnt;
	vector< int > ids;
	vector< int > froms;
	using P = pair< T, int >;//dist, id

	BFS(int N, T initDist)
	: N(N)
	, dist(N, initDist)
	, cnt(N,0)
	, ids(N,-1)
	, froms(N,-1)
	{}

	BFS() = default;

	void solve(const Graph< T >& G, int s, int g=-1, bool count = false){
		dist[s] = 0;
		cnt[s] = 1;
		queue<P> que;//dist, to
		que.push({0,s});

		while(!que.empty()){
			auto [d,p] = que.front();
			// T d = que.front().first;
			// int p = que.top().second;
			que.pop();
			if(d>dist[p]) continue;
			if(g>=0 && d>dist[g]) continue;

			for(const auto& e:G[p]){
				if(dist[e.to]>dist[p]+e.cost){
					dist[e.to] = dist[p] + e.cost;
					que.push({dist[e.to], e.to});
					ids[e.to] = e.id;
					froms[e.to] = e.from;
					if(count) cnt[e.to] = cnt[p];
				}
				else if(count && dist[e.to] == dist[p]+e.cost){
					cnt[e.to] += cnt[p];
					// cnt[to] %= MOD;
				}	
			}
		}
	}

	//頂点id
	vector<int> find_path(int g){
		vector<int> path;
		if(froms[g]==-1) return path;
		int p = g;
		while(froms[p]!=-1){
			path.push_back(p);
			p = froms[p];
		}
		path.push_back(p);
		reverse(path.begin(), path.end());
		return path;
	}
	//Edge id
	vector<int> find_edges(int g){
		vector<int> edge_ids;
		if(ids[g]==-1) return edge_ids;
		int p = g;
		while(ids[p]!=-1){
			edge_ids.push_back(ids[p]);
			p = froms[p];
		}
		reverse(edge_ids.begin(), edge_ids.end());
		return edge_ids;
	}
};

/*
    int N; cin>>N;
    int M; cin>>M;

    Edges<int> E = readE<int>(M, -1, false);//辺数，index, weight
    Graph<int> G(N, E, false);//頂点数，Edges, 有向

    Dijkstra<int> di(N, INF);//頂点数，初期距離
    di.solve(G, 0, 0, false);//G, start, goal, 通り数える

    EL(di.dist)
    EL(di.find_path(N-1))
    EL(di.find_edges(N-1))
*/


