#pragma once

struct UndoUnionFind {
   vector< int > data;// if <0 : size else: leader
   stack< pair< int, int > > history;//

   UndoUnionFind(int sz) {
      data.assign(sz, -1);
   }

   bool merge(int x, int y) {
      x = leader(x), y = leader(y);
      history.emplace(x, data[x]);
      history.emplace(y, data[y]);
      if(x == y) return (false);
      if(data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
      return (true);
   }

   bool same(int x, int y){
      return leader(x) == leader(y);
   }

   int leader(int k) {
      if(data[k] < 0) return (k);
      return (leader(data[k]));
   }

   int size(int k) {
      return (-data[leader(k)]);
   }

   void undo() {
      data[history.top().first] = history.top().second;
      history.pop();
      data[history.top().first] = history.top().second;
      history.pop();
   }

   void snapshot() {
      while(history.size()) history.pop();
   }

   void rollback() {
      while(history.size()) undo();
   }
};