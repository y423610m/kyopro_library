#pragma once

#include "../graph_template.hpp"

/*
閉路１つ列挙(無向)
無向グラフcheckLoop

有向のcheckLoopは強連結成分分解ACL::sccに頼る

*/

template<typename T=int>
struct CycleDetection{
    int N;
    bool directed;

    CycleDetection(int N)
    :N(N)
    ,inLoop(N, true)
    {}

    vector<bool> inLoop;
    void checkLoop(const Graph<T>& G){
        /*
            inLoop更新
            各頂点の次元をみて，1以下（末端，単独)の点から削除．
        */
        vector<int> deg(N);
        for(int i=0;i<N;i++) deg[i] = G[i].size();
        queue<int> que;
        for(int i=0;i<N;i++) if(deg[i]<=1){
            deg[i] = 0;
            que.push(i);
        }
        while(!que.empty()){
            int p = que.front(); que.pop();
            inLoop[p] = false;
            for(auto& e: G[p]){
                deg[e.to]--;
                if(deg[e.to]==1) que.push(e.to);
            }
        }
    }


    vector<int> path;
    vector<int> edges;
    //searchAll:閉路見つけたら終わりなのか，全部探すのか
    void findOneLoop(const Graph<T>& G){
        vector<int> froms(N,-1);
        vector<int> ids(N,-1);
        vector<int> used(N, 0);
        auto dfs = [&](auto dfs, int idx, int par=-1)->bool {
            used[idx] = 1;
            for(auto& e:G[idx]){
                // //無向なら逆流禁止
                // if(!directed&&e.to==par) continue;
                if(e.to==par) continue;
                //未探索なら，経路覚えて継続
                if(used[e.to]==0){
                    froms[e.to] = idx;
                    ids[e.to] = e.id;
                    if(dfs(dfs, e.to, idx)) return true;
                }
                //閉路発見した
                else if(used[e.to]==1){
                    int cur = idx;
                    path.push_back(e.to);
                    edges.push_back(e.id);
                    while(cur!=e.to){
                        path.push_back(cur);
                        edges.push_back(ids[cur]);
                        cur = froms[cur];
                    }
                    path.push_back(cur);
                    return true;
                }
            }
            used[idx] = 2;
            return false;
        };

        for(int i=0;i<N;i++){
            if(used[i]==0&&dfs(dfs, i)){
                reverse(path.begin(), path.end());
                reverse(edges.begin(), edges.end());
                // for(int j=0;j<(int)path.size();j++) inLoop[path[i]] = true;
                return;
            }
        }
    }
};