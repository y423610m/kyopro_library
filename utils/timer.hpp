#ifndef TIMER
#define TIMER

struct Timer{
    clock_t start;
    Timer(){start = clock(); lastTime = clock();}
    bool pass(int timeMs){
        if((clock()-start)*1000/CLOCKS_PER_SEC > timeMs) return true;
        return false;
    }
    int time(){
        return (clock()-start)*1000/CLOCKS_PER_SEC;
    }

    clock_t lastTime;
#ifndef ONLINE_JUDGE
    string lastState;
    unordered_map<string, clock_t> timeForStateUs;
    unordered_map<string, int> cntForStateUs;
    void log(const char* file, const char* func, size_t line, const char* comment){
        clock_t now = clock();
        if(lastState!=""){
            timeForStateUs[lastState] += (now-lastTime) * 1'000'000/CLOCKS_PER_SEC;
            cntForStateUs[lastState]++;
        }
        lastTime = now;

        lastState = "";
        lastState += file;
        lastState += "/";
        lastState += func;
        lastState += "/";
        lastState += to_string(line);
        if(comment){
            lastState += "/";
            lastState += comment;
        }
    }
#endif

    void print(){
#ifndef ONLINE_JUDGE
        clock_t now = clock();
        if(lastState!=""){
            timeForStateUs[lastState] += (now-lastTime) * 1'000'000/CLOCKS_PER_SEC;
            cntForStateUs[lastState]++;
        }
        cerr<<"----timer result [us]----"<<endl;
        cerr<<fixed<<setprecision(2);
        for(auto [state, time]:timeForStateUs){
            int cnt = cntForStateUs[state];
            double rate = 1.0;
            rate = rate * time / (now - start) / 1'000'000 * CLOCKS_PER_SEC * 100;
            ES(state) ES(time) ES(cnt) EL(rate)
        }
#endif //ONLINE_JUDGE
    }
};

#ifdef ONLINE_JUDGE
    #define TIMER_LOG(timer, comment) while(0){}
#else
    #define TIMER_LOG(timer, comment) (timer).log(__FILE__, __func__, __LINE__, comment)
#endif //ONLINE_JUDGE

#endif //TIMER