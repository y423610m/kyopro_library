#ifndef SOLVER
#define SOLVER
#include "template.hpp"
#include "input.hpp"
#include "state.hpp"
#include "utils/timer.hpp"
//Timer timer;
//if(timer.pass()) PL(timer.time())
//TIMER_LOG(timer, "comment")
//timer.print();


struct Solver{

   Timer timer;
   Input input;
   Solver(){
      
   }
   
   AnswerPtr solve(){
      AnswerPtr best(new Answer(input));
      naive(best);

      while(!timer.pass(2000)){
         AnswerPtr ans(new Answer(input));
         naive(ans);
         if(best->score > ans->score){
            best = ans;
         }
      }


      timer.print();

      return best;
   }

   void naive(AnswerPtr ans){
      EL("naive")
      TIMER_LOG(timer, "");


   }

};


#endif //SOLVER