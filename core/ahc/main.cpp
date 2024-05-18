#include "solver.hpp"

#define endl "\n"


int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   // int TT = 1;
   // //cin>>TT;
   // for(int tt = 0; tt<TT; tt++) solve();

   Solver solver;
   StatePtr state = solver.Solve();

   state->Print();

   return 0;
}
