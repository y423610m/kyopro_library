#ifndef ANSWER
#define ANSWER

struct Answer{
   V<int> ans;
   Answer(const Input& input){
      
   }

   //解出力
   void print(){
      cerr<<"----Answer result----"<<endl;
      PL(ans)
   }

   ll score = 0;
   ll calcScore(const Input& input){
      return score;
   }


};

using AnswerPtr = shared_ptr<Answer>;

#endif //ANSWER