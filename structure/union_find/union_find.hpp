#pragma once

using ll = long long;

template<typename KeyT, typename ParentT, typename SizeT, typename ChildT, typename WeightT>
struct UnionFindBase
{

   int n;
   ParentT parent;//unordered_map<KeyT, KeyT> or vector<int>
   SizeT sz;//unordered_map<KeyT, int> or vetor<int>
   ChildT child;//unordered_map<KeyT, vector<KeyT>> or vector<vector<int>>
   WeightT diffWeight;

   UnionFindBase(int n) : n(n)
   {
   }

   bool same(KeyT a, KeyT b){
      return leader(a) == leader(b);
   }

   bool merge(KeyT a, KeyT b, ll w = 0){
      auto MergeF = [&](KeyT x, KeyT y)->bool {return sz[x] >= sz[y];};
      auto UpdateF = [&](KeyT x, KeyT y)->void {};
      return mergeMU(a, b, MergeF, UpdateF, w);
   }

   bool mergeM(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, ll w = 0){
      auto UpdateF = [&](KeyT x, KeyT y)->void {};
      return mergeMU(a, b, MergeF, UpdateF, w);
   }

   bool mergeU(KeyT a, KeyT b, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      auto MergeF = [&](KeyT x, KeyT y)->bool {return sz[x] >= sz[y];};
      return mergeMU(a, b, MergeF, UpdateF, w);
   }

   // template <typename MergeT, typename UpdateT>
   // bool mergeMU(KeyT a, KeyT b, MergeT MergeF, UpdateT UpdateF){
   bool mergeMU(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      w += weight(a);
      w -= weight(b);
      KeyT x = leader(a);
      KeyT y = leader(b);
      if(x==y) return false;
      if (!MergeF(x, y)) swap(x, y), w=-w;
      sz[x] += sz[y];
      parent[y] = x;
      child[x].emplace_back(y);
      UpdateF(x, y);
      diffWeight[y] = w;
      return true;
   }

   KeyT leader(KeyT x){
      if(parent[x]==x) return x;
      KeyT l = leader(parent[x]);// Need to call this before updating weight.
      diffWeight[x] += diffWeight[parent[x]];
      return parent[x] = l;
   }

   ll diff(KeyT x, KeyT y) {
      return weight(y) - weight(x);
   }

   ll weight(KeyT x) {
      leader(x);
      return diffWeight[x];
   }

   int size(KeyT x) {
      return sz[leader(x)];
   }

   int size(){
      return parent.size();
   }

   vector<KeyT> group(KeyT a){
      a = leader(a);
      vector<KeyT> mem;
      auto dfs = [&](auto dfs, const KeyT& x)->void {
         mem.push_back(x);
         for(const KeyT& nxt: child[x]){
            dfs(dfs, nxt);
         }
      };
      dfs(dfs, a);
      return mem;
   }
};

struct UnionFind : public UnionFindBase<int, vector<int>, vector<int>, vector<vector<int>>, vector<ll> >
{
   UnionFind(int n) : UnionFindBase(n)
   {
      parent.resize(n, -1);
      sz.resize(n, 1);
      for(int i=0;i<n;i++) parent[i] = i;
      child.resize(n);
      diffWeight.resize(n);
   }

   vector<vector<int>> groups(){
      vector<vector<int>> result;
      for(int i=0;i<n;i++) if(parent[i]==i){
         result.emplace_back(group(i));
      }
      return result;
   }
};

template <typename KeyT>
struct UnionFindUM : public UnionFindBase<KeyT, unordered_map<KeyT, KeyT>, unordered_map<KeyT, int>, unordered_map<KeyT, vector<KeyT>>, unordered_map<KeyT, ll> >
{

   using base = UnionFindBase<KeyT, std::unordered_map<KeyT, KeyT>, std::unordered_map<KeyT, int>, unordered_map<KeyT, vector<KeyT>>, unordered_map<KeyT, ll>>;
   using base::UnionFindBase;
   // using UnionFindBase<KeyT, std::unordered_map<KeyT, KeyT>, std::unordered_map<KeyT, int>>::UnionFindBase;

   UnionFindUM() : base(0)
   {
   }

   void _EnsureExistance(const KeyT& x){
      if( this->parent.find(x) == this->parent.end() ) {
         this->n++;
         this->parent[x] = x;
         this->sz[x] = 1;
         this->diffWeight[x] = 0;
      }
   }

   bool same(KeyT a, KeyT b){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::leader(a) == base::leader(b);
   }

   bool merge(KeyT a, KeyT b, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::merge(a, b, w);
   }

   bool mergeM(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::mergeM(a, b, MergeF, w);
   }

   bool mergeU(KeyT a, KeyT b, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::mergeU(a, b, UpdateF, w);
   }

   bool mergeMU(KeyT a, KeyT b, std::function<bool(KeyT, KeyT)> MergeF, std::function<void(KeyT, KeyT)> UpdateF, ll w = 0){
      _EnsureExistance(a);
      _EnsureExistance(b);
      return base::mergeMU(a, b, MergeF, UpdateF, w);
   }

   KeyT leader(KeyT x){
      _EnsureExistance(x);
      return base::leader(x);
   }

   int size(KeyT x) {
      _EnsureExistance(x);
      return base::size(x);
   }

   ll diff(KeyT x, KeyT y) {
      _EnsureExistance(x);
      _EnsureExistance(y);
      return base::diff(x, y);
   }

   ll weight(KeyT x){
      _EnsureExistance(x);
      return base::weight(x); 
   }

   vector<KeyT> group(KeyT a){
      _EnsureExistance(a);
      return base::group(a);
   }

   vector<vector<KeyT>> groups(){
      vector<vector<KeyT>> result;
      for(const auto& [x, p]:this->parent) if(x==p) {
         result.emplace_back(group(x));
      }
      return result;
   }
};
