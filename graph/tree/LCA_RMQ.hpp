#include "graph/graph_template.hpp"
#include "structure/others/sparse_table.hpp"

template<typename T>
struct LCA_RMQ{
    int N;
    vector<int> in;
    vector<int> out;
    vector<int> depth;//depth[i]:=頂点iの深さ
    vector<int> order;//dep[i]:=時刻iの頂点
    vector<int> dep;//dep[i]:=時刻iの深さ
    using F = function<int(int,int)>;
    SparseTable<int, F> st;

    LCA_RMQ(int N, const Graph<T>& G, int root = 0)
    :N(N)
    ,in(N)
    ,out(N)
    ,depth(N,-1)
    {
        order.reserve(N*3-1);
        dep.reserve(N*3-1);

        auto dfs = [&](auto dfs, int v, int d)->void {
            depth[v] = d;
            in[v] = order.size();
            order.emplace_back(v);
            dep.emplace_back(d);
            for(const auto& e:G[v]) if(depth[e.to]==-1){
                dfs(dfs, e.to, d+1);
                order.emplace_back(v);
                dep.emplace_back(d);
            }
            out[v] = order.size();
            order.emplace_back(v);
            dep.emplace_back(d);
        };
        dfs(dfs, root, 0);
        vector<int> vs(order.size());
        iota(vs.begin(), vs.end(), 0);
        F f = [&](int a, int b) { return dep[a] < dep[b] ? a : b; };
        st = get_sparse_table(vs, f);
    }

    int lca(int x, int y) const{
        if(in[x]>in[y]) swap(x,y);
        return x == y ? x : order[st.fold(in[x], in[y])];
    }

    int size(){
        return int(order.size());
    }

    /*
        int N; cin>>N;
        Edges<int> E = readE<int>(N-1, -1, false);//weighted
        Graph<int> G(N, E, false);//directed
        LCA_RMQ tree(N, G, 0);//root

        EL(tree.lca(0,4))//共通祖先id
    */
};

