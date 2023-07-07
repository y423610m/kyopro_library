#pragma once

/*
struct Edge;
edges = vectpr<Edge>;
readE()
Graph G;

TO DO: find_path, find_edges
*/


//////////////////Graph Template
template<typename CostT=int>//cost type
struct Edge{
    int from, to;
    CostT cost;
    int id, used;

    Edge() = default;

    Edge(int from, int to, CostT cost = 1, int id = -1, int used = false)
    : from(from)
    , to(to)
    , cost(cost)
    , id(id)
    , used(used){}

    Edge(ll from, ll to, CostT cost = 1, int id = -1, int used = false)
    : from(from)
    , to(to)
    , cost(cost)
    , id(id)
    , used(used){}

    operator int() const { return to; }
};

// bool operator<(Edge a, Edge b){
//     return a.cost<b.cost;
// }

template <typename CostT = int>
using Edges = vector< Edge< CostT > >;

template<typename CostT>
vector< Edge< CostT > > readE(int M, int padding = -1, bool weighted = false){
    vector< Edge< CostT > > E;
    E.reserve(M);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u += padding;
        v += padding;

        CostT w = 1;
        if(weighted) cin>>w;

        E.emplace_back(u,v,w,i,0);
    }
    return E;
}




template <typename CostT = int>//cost type
struct Graph{
    vector< vector< Edge< CostT > > > g;
    int id;

    Graph() = default;

    explicit Graph(int n):g(n), id(0){}

    Graph(int n, const Edges<T>& E, bool directed = false, bool reverse = false):g(n), id(0){
        for(const auto& e: E){
            if(directed){
                if(!reverse){
                    g[e.from].emplace_back(e);
                }
                else{
                    g[e.to].emplace_back(e.to, e.from, e.cost, e.id, e.used);
                }
            }
            else{
                g[e.from].emplace_back(e);
                g[e.to].emplace_back(e.to, e.from, e.cost, e.id, e.used);
            }
        }
    }

    size_t size()const{return g.size();}

    void add_directed_edge(int from, int to, CostT cost = 1){
        g[from].emplace_back(from, to, cost, id++, 0);
    }

    void add_edge(int from, int to, CostT cost = 1){
        g[from].emplace_back(from, to, cost, id, 0);
        g[to].emplace_back(to, from, cost, id++, 0);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false){
        for(int i=0;i<M;i++){
            int u,v; cin>>u>>v;
            u += padding; v += padding;

            CostT w = 1;
            if(weighted) cin>>w;

            if(directed) add_directed_edge(u,v,w);
            else add_edge(u,v,w);
        }
    }

    inline vector< Edge< CostT > > &operator[](const int& k){return g[k];}
    inline const vector< Edge< CostT > > &operator[](const int& k)const{return g[k];}

};

/*
    int N,M; cin>>N>>M;
    Edges<int> E = readE<int>(M, -1, true);//weighted?
    Graph<int> G(N, E, true);//directed?
    //Graph<int> G(N); G.read(M, -1, true, true);
*/

