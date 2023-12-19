template<typename T>
struct CumulativeSum2D{
   using ll = long long int;
   vector<vector<T>> data;
   ll _H, _W;

   CumulativeSum2D(ll h, ll w):
   _H(h),
   _W(w)
   // data(_H, vector<T>(_W))
   {
      data = vector<vector<T>>(_H+1, vector<T>(_W+1));
   }

   void set(ll h, ll w, T value){
      data[h+1][w+1] = value;
   }

   void build(){
      for(ll h=0;h<_H;h++){
         for(ll w=0;w<_W;w++){
            data[h+1][w+1] += data[h][w+1] + data[h+1][w] - data[h][w];
         }
      }
   }

   T _get(ll H, ll W){
      ll ans = 0;
      //left up
      ans += data[_H][_W] * (H/_H) * (W/_W);
      // left down
      ans += data[H%_H][_W] * (W/_W);
      // right up
      ans += data[_H][W%_W] * (H/_H);
      // right up
      ans += data[H%_H][W%_W];

      return ans;
   }

   T get(ll h, ll w, ll H, ll W){
      return _get(H, W) - _get(h, W) - _get(H, w) + _get(h, w);
   }

};