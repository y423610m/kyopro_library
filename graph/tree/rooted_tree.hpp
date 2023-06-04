#include "graph/graph_template.hpp"

template<typename T>
struct RootedTree{
    int N;
    vector<int> depth;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> numOfDescendants;
    vector<T> dist;
    V<int> farestDescendant;

    RootedTree(int N, const Graph<T>& G, int root)
    :N(N)
    ,depth(N,-1)
    ,parent(N,-1)
    ,children(N)
    ,numOfDescendants(N, 0)
    ,dist(N, -1)
    ,farestDescendant(N)
    {
        parent[root] = root;
        dist[root] = 0;
        auto dfs = [&](auto dfs, int v, int d)->void {
            depth[v] = d;
            farestDescendant[v] = v;
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                parent[e.to] = v;
                dist[e.to] = dist[v] + e.cost;
                children[v].emplace_back(e.to);
                dfs(dfs, e.to, d+1);
                numOfDescendants[v] += numOfDescendants[e.to]+1;
                if(depth[farestDescendant[v]]<depth[farestDescendant[e.to]]) farestDescendant[v] = farestDescendant[e.to];
            }
            return;
        };
        dfs(dfs, root, 0);
    }
};

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, false);//weighted?
    Graph<int> G(N, E, false);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);

    RootedTree rt(N, G, 0);//2nd arg:root

    EL(rt.depth)
    EL(rt.parent)
    EL(rt.numOfDescendants)
    rep(i,N) EL(rt.children[i])
    EL(rt.farestDescendant)
    //Edgeは親->子が含まれていれば,有向でも無向でもOK
    rootの親はroot自身
*/