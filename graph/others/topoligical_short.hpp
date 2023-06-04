
    auto topological_sort = [&](const auto& G)->vector<int> {
        V<int> ans;
        V<int> in(G.size());
        rep(i,G.size()) for(const auto& e:G[i]) in[e.to]++;
        queue<int> que;
        V<bool> done(G.size(), false);
        rep(i,G.size()) if(in[i]==0) que.push(i);
        while(!que.empty()){
            int p = que.front(); que.pop();
            ans.push_back(p);
            done[p] = true;
            for(const auto e:G[p]){
                in[e.to]--;
                if(in[e.to]==0){
                    que.push(e.to);
                }
            }
        }
        return ans;
    };