#pragma once

#include "../graph_template.hpp"

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
#endif

template<typename T>
struct Kruskal{
	int N;
	T total;
	vector<int> used;//edge id

	Kruskal(int N)
	:N(N)
	,total(0)
	{used.reserve(N);}

	void solve(Edges<T>& E){
		sort(E.begin(), E.end(), [](const Edge<T>& a, const Edge<T>& b){
			return a.cost<b.cost;
		});

		dsu tree(N);
		for(auto& e:E){
			if(!tree.same(e.from, e.to)){
				tree.merge(e.from, e.to);
				used.push_back(e.id);
				total += e.cost;
				e.used = 1;
			}
		}
	}
};