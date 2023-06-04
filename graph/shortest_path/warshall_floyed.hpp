#pragma once

#include "../graph_template.hpp"


template<typename T = int>
struct WarshallFloyed{
	int N;
	vector<vector<T>> dist;
	vector<vector<int>> froms;
	vector<vector<int>> ids;

	WarshallFloyed(int N, const Edges<T>& E, int initDist, bool directed)
	: N(N)
	, dist(N, vector<T>(N, initDist))
	, froms(N, vector<int>(N, -1))
	, ids(N, vector<int>(N, -1))
	{
		for(int i=0;i<N;i++) dist[i][i] = 0;
		for(const auto& e:E){
			int u = e.from;
			int v = e.to;
			int w = e.cost;
			dist[u][v] = w;
			froms[u][v] = u;
			ids[u][v] = e.id;
			if(directed) continue;
			swap(u,v);
			dist[u][v] = w;
			froms[u][v] = u;
			ids[u][v] = e.id;
		}
	}


	void solve(){
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(dist[i][j] > dist[i][k]+dist[k][j]){
						dist[i][j] = dist[i][k]+dist[k][j];
						froms[i][j] = froms[k][j];
						ids[i][j] = ids[k][j];
					}
				}
			}
		}
	}

	vector<int> find_path(int s, int g){
		vector<int> path;
		if(froms[s][g]==-1) return path;
		int p = g;
		while(p!=s){
			path.push_back(p);
			p = froms[s][p];
		}
		path.push_back(p);
		reverse(path.begin(), path.end());
		return path;
	}

	vector<int> find_edges(int s, int g){
		vector<int> edge_ids;
		if(froms[s][g]==-1) return edge_ids;
		int p = g;
		while(p!=s){
			edge_ids.push_back(ids[s][p]);
			p = froms[s][p];
		}
		reverse(edge_ids.begin(), edge_ids.end());
		return edge_ids;
	}
};

