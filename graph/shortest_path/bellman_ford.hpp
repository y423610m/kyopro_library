#pragma once

#include "../graph_template.hpp"

template<typename T = int>
struct BellmanFord{
	int N;
	bool _has_minus_loop = false;
	vector<T> dist;
	vector<int> ids;
	vector<int> froms;

	BellmanFord(int N, T initDist)
	: N(N)
	, dist(N, initDist)
	, ids(N, -1)
	, froms(N, -1)
	{}


	bool solve(const Edges<T>& E, int s, bool directed){
		dist[s] = 0;

		int cnt_loop = 0;
		while(true){
			bool updated = false;
			for(const auto& e:E){
				int from = e.from;
				int to = e.to;
				T cost = e.cost;
				int id = e.id;
				if(dist[from]+cost<dist[to]){
					dist[to] = dist[from]+cost;
					froms[to] = from;
					ids[to] = id;
					updated = true;
				}
				if(directed) continue;
				swap(to,from);
				if(dist[from]+cost<dist[to]){
					dist[to] = dist[from]+cost;
					froms[to] = from;
					ids[to] = id;
					updated = true;
				}
			}
			if(!updated) break;
			cnt_loop++;
			if(cnt_loop>E.size()) return true;
		}
		return false;
	}
	
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

	vector<int> find_edges(int g){
		vector<int> path_ids;
		if(froms[g]==-1) return path_ids;
		int p = g;
		while(froms[p]!=-1){
			path_ids.push_back(ids[p]);
			p = froms[p];
		}
		reverse(path_ids.begin(), path_ids.end());
		return path_ids;
	}
};

