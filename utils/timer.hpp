#pragma once

struct Timer{
    clock_t start;
    Timer(){start = clock();}
    bool pass(int ms){
        if((clock()-start)*1000/CLOCKS_PER_SEC>ms) return true;
        return false;
    }
    int time(){
        return (clock()-start)*1000/CLOCKS_PER_SEC;
    }

#ifndef ONLINE_JUDGE
    string lastState;
    clock_t lastTime;
    unordered_map<string, int> timeForState;
#endif //ONLINE_JUDGE
    void SetState(const string& state){
#ifndef ONLINE_JUDGE
        clock_t now = clock();
        if(lastState!=""){
            timeForState[lastState] += (now-lastTime) *1000/CLOCKS_PER_SEC;
        }
        lastTime = now;
        lastState = state;
#endif //ONLINE_JUDGE
    }
    void Print(){
#ifndef ONLINE_JUDGE
        for(auto [state, time]:timeForState){
            ES(state) EL(time)
        }
#endif //ONLINE_JUDGE
    }
};