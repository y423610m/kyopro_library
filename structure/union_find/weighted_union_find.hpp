/*
parent_or_size
*/
// template<class T> struct WeightedUnionFind {
//     vector<int> par;
//     vector<int> rank;
//     vector<T> diff_weight;

//     WeightedUnionFind(int n = 1)
//     :par(n,-1), rank(n,0), diff_weight(n,0)
//     {}

//     int leader(int x) {
//         if (par[x] == -1) {
//             return x;
//         }
//         else {
//             int r = leader(par[x]);
//             diff_weight[x] += diff_weight[par[x]];
//             return par[x] = r;
//         }
//     }

//     T weight(int x) {
//         leader(x);
//         return diff_weight[x];
//     }

//     bool same(int x, int y) {
//         return leader(x) == leader(y);
//     }

//     bool merge(int x, int y, T w) {
//         w += weight(x); w -= weight(y);
//         x = leader(x); y = leader(y);
//         if (x == y) return false;
//         if (rank[x] < rank[y]) swap(x, y), w = -w;
//         if (rank[x] == rank[y]) ++rank[x];
//         par[y] = x;
//         diff_weight[y] = w;
//         return true;
//     }

//     T diff(int x, int y) {
//         return weight(y) - weight(x);
//     }
//     /*
//     WeightedUnionFind<ll> tree(N);
//     if(!tree.same(x,y)) tree.merge(x,y,w);// weight[y] = weight[x]+w;
//     tree.leader();
//     tree.diff(x,y);//weight(y)-weight(x);
//     abc277 D2
//     */
// };

template<class T> struct WeightedUnionFind {
    vector<int> par;
    vector<int> sz;
    vector<T> diff_weight;

    WeightedUnionFind(int n = 1)
    :par(n,-1), sz(n,1), diff_weight(n,0)
    {}

    int leader(int x) {
        if (par[x] == -1) {
            return x;
        }
        else {
            int l = leader(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = l;
        }
    }

    T weight(int x) {
        leader(x);
        return diff_weight[x];
    }

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    bool merge(int x, int y, T w) {
        w += weight(x); w -= weight(y);
        x = leader(x); y = leader(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y), w = -w;
        sz[x] += sz[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }

    int size(){
        return sz.size();
    }

    int size(int i){
        return sz[leader(i)];
    }

    /*
    WeightedUnionFind<ll> tree(N);
    if(!tree.same(x,y)) tree.merge(x,y,w);// weight[y] = weight[x]+w;
    tree.leader();
    tree.diff(x,y);//weight(y)-weight(x);
    abc277 D2
    */
};