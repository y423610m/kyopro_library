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
   
   StatePtr Solve(){
      StatePtr best(new State(input));
      _Naive(best);

      while(!timer.pass(2000)){
         StatePtr state(new State(input));
         _Naive(state);
         if(best->score > state->score){
            best = state;
         }
      }


      timer.print();

      return best;
   }

   void _Naive(StatePtr state){
      EL("naive")
      TIMER_LOG(timer, "");


   }

};


#endif //SOLVER