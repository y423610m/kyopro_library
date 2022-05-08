#include <bits/stdc++.h>
using namespace std;

struct dsu{
    int N;
    vector<int> parent, rank, size_;
    dsu(int n){
        N=n;
        parent.resize(n);
        rank.resize(n);
        size_.resize(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int leader(int x){
        if(parent[x]==x) return x;
        else return parent[x]=leader(parent[x]);
    }

    int merge(int x, int y){
        x = leader(x);
        y = leader(y);
        if(x==y) return x;

        if(rank[x]<rank[y]){
            parent[x] = y;
            size_[y] += size_[x];
            return y;
        }
        else if(rank[x]>rank[y]){
            parent[y] = x;
            size_[x] += size_[y];
            return x;
        }
        else{
            parent[x] = y;
            size_[y] += size_[x];
            rank[y]++;
            return y;
        }
    }

    bool same(int x, int y){
        x = leader(x);
        y = leader(y);
        return x==y;        
    }

    int size(int x){
        x = leader(x);
        return size_[x];
    }

    vector<vector<int>> groups(){
        vector<int> Leader(N), group_size(N);
        for(int i=0;i<N;i++){
            Leader[i] = leader(i);
            group_size[Leader[i]]++;
        }
        vector<vector<int>> result(N);
        for(int i=0;i<N;i++){
            result[i].reserve(group_size[i]);
        }
        for(int i=0;i<N;i++){
            result[Leader[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

};

int main(){
    dsu DSU(10);

    if(!DSU.same(0,1)) cout<<"0 1 different"<<endl;
    if(!DSU.same(0,7)) cout<<"0 7 different"<<endl;

    DSU.merge(0,1);
    DSU.merge(0,2);
    DSU.merge(0,3);
    DSU.merge(8,9);

    if(DSU.same(0,1)) cout<<"0 1 same"<<endl;
    if(!DSU.same(0,7)) cout<<"0 7 different"<<endl;

    for(int i=0;i<10;i++) cout<<DSU.size(i)<<" ";
    cout<<endl;

    auto groups = DSU.groups();
    for(int i=0;i<groups.size();i++){
        for(int j=0;j<groups[i].size();j++) cout<<groups[i][j]<<" ";
        cout<<endl;
    }

    return -1;
}