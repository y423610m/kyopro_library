#pragma once

#include "graph/graph_template.hpp"

template <typename T>
struct TreeDiameter{
    int N;
    vector<T> dist0;//0からの距離
    vector<T> distl;//lからの距離
    vector<T> distr;//rからの距離
    int l, r;//両端．先にl,　そのあとr求める
    T Diameter;

    TreeDiameter(int N, const Graph<T>& G, T initDist = INF, bool calcDistR = false):
    N(N)
    {
        vector<T> dist(N, initDist);
        dist[0] = 0;
        int FarestNode = 0;
        T MaxDist = 0;
        auto dfs = [&](auto dfs, int p)->void {
            for(const auto& e:G[p]){
                if(dist[e.to]>dist[p]+e.cost){
                    dist[e.to] = dist[p]+e.cost;
                    if(MaxDist<dist[e.to]){
                        MaxDist = dist[e.to];
                        FarestNode = e.to;
                    }
                    dfs(dfs, e.to);
                }
            }
        };
        dfs(dfs, 0);
        swap(dist, dist0);
        l = FarestNode;

        dist = vector<T>(N, initDist);
        dist[l] = 0;
        FarestNode = l;
        MaxDist = 0;
        dfs(dfs, l);
        swap(dist, distl);
        r = FarestNode;
        Diameter = MaxDist;

        if(calcDistR){
            dist = V<T>(N, initDist);
            dist[r] = 0;
            dfs(dfs, r);
            swap(dist, distr);
        }
    }

/*
    int N; cin>>N;
    Edges<int> E = readE<int>(N-1, -1, false);
    Graph<int> G(N, E, false, false);

    TreeDiameter tree(N, G, INF, false);//needDistFromR?
    ES(tree.l) EL(tree.r)
    EL(tree.Diameter)
*/

};