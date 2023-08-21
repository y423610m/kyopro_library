#pragma once

// Σ ( ai * aj * ak ... * az) s.t. i<j<...<z
template <typename T>
T sum_of_K_products(const vector<T>& A, int K){
   if(K==0) return T(A.size());
   if(K>A.size()) return 0;
   T ans = 0;
   vector<T> acc = A;
   acc.push_back(0);
   int n = A.size();
   for(int k=1;k<K;k++){
      for(int i=n-1;i>=0;i--) acc[i] += acc[i+1];
      for(int i=0;i<n;i++) acc[i] = A[i] * acc[i+1];
   }
   for(int i=0;i<n;i++) ans += acc[i];

   return ans;
}