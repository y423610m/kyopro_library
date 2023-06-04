#pragma once


#include "../graph_template.hpp"

/*
ダイクストラ風に小さな辺から選ぶ
*/

template<typename T = int>
struct Prim{
	
	int N;
	T total;
	vector<T> dist;
	vector<bool> used;
	vector<int> froms;
	vector<int> ids;

	Prim(int N, T initDist)
	:N(N)
	,total(0)
	,dist(N, initDist)
	,used(N,false)
	,froms(N,-1)
	,ids(N,-1)//edge_ids
	{}

	void solve(const Graph<T>& G, int s = 0){
		using P = pair<T,int>;//dist, pos
		priority_queue<P,vector<P>,greater<P>> que;
		que.push({0,s});//頂点0からスタート
		dist[s] = 0;
		while(!que.empty()){
			P p = que.top();
			que.pop();
			if(used[p.second]) continue;
			used[p.second] = true;
			total += p.first;
			for(const auto& e:G[p.second]){
				if(dist[e.to]<=e.cost) continue;
				if(used[e.to]) continue;
				dist[e.to] = e.cost;
				que.push({e.cost, e.to});
				froms[e.to] = e.from;
				ids[e.to] = e.id;
			}
		}
	}
};

/* 無向グラフのみ！！！
    int N; cin>>N;
    int M; cin>>M;
    int s = 0;

    Edges<ll> E = readE<ll>(M, 0, true);
    Graph<ll> G(N, E, false);

    Prim<ll> prim(N, INF);
    prim.solve(G, s);

    PL(prim.total)

	retuen;
*/