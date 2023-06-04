#include "graph/graph_template.hpp"

template<typename T>
struct LCADoubling{
    int N;
    vector<int> depth;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> numOfChildren;
    vector<T> dist;//rootからの距離

    int LOG;
    vector<vector<int>> table;

    LCADoubling(int N, const Graph<T>& G, int root)
    :N(N)
    ,depth(N,-1)
    ,parent(N,-1)
    ,children(N)
    ,numOfChildren(N, 0)
    ,dist(N, -1)
    ,LOG(32-__builtin_clz(N))
    ,table(LOG, vector<int>(N, -1))
    {

        parent[root] = root;
        dist[root] = 0;

        table[0][root] = -1;
        auto dfs = [&](auto dfs, int v, int d)->int {
            depth[v] = d;
            int num = 0;
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                parent[e.to] = v;
                dist[e.to] = dist[v] + e.cost;
                children[v].emplace_back(e.to);
                num += dfs(dfs, e.to, d+1);
                table[0][e.to] = v;
            }
            numOfChildren[v] = num;
            return num + 1;
        };
        dfs(dfs, root, 0);

        for(int k=0;k+1<LOG;k++){
            for(int i=0;i<N;i++){
                if(table[k][i] == -1) table[k+1][i] = -1;
                else table[k+1][i] = table[k][table[k][i]];
            }
        }
    }

    int lca(int u, int v){
        if(depth[u]>depth[v]) swap(u,v);
        v = climb(v, depth[v]-depth[u]);
        if(u==v) return u;
        for(int i=LOG-1;i>=0;i--){
            if(table[i][u]!=table[i][v]){
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int climb(int u, int k){

        if(depth[u]<k) return -1;
        for(int i=LOG-1;i>=0;i--){
            if((k>>i)&1){
                u = table[i][u];
            }
        }
        return u;
    }

    int distance(int u, int v){
        return dist[u] + dist[v] - dist[lca(u,v)]*2;
    }

    /*
        int N; cin>>N;
        Edges<int> E = readE<int>(N-1, -1, false);
        Graph<int> G(N, E, false);

        LCADoubling tree(N, G, 0);

        EL(tree.lca(0,2));
        EL(tree.dist(0,2));

        EL(tree.depth[0])
        EL(tree.numOfChildren[0])
        EL(tree.parent[0])
        EL(tree.dist[0])
    */
};

