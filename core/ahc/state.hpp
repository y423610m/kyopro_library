#ifndef STATE
#define STATE

struct State{
   V<int> ans;
   State(const Input& input){
      
   }

   //解出力
   void print(){
      cerr<<"----State result----"<<endl;
      PL(ans)
   }

   ll score = 0;
   ll calcScore(const Input& input){
      return score;
   }


};

using StatePtr = shared_ptr<State>;

#endif //STATE