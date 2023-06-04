#pragma once

//中央値を求められるqueue. pair型で出力
template<typename T>
struct MiddleQueue{
    priority_queue<ll> L;
    priority_queue<ll,V<ll>,greater<ll>> R;
    MiddleQueue(T l, T r){
        L.push(l);
        R.push(r);
    }

    void push2(T x){
        L.push(x);
        R.push(L.top());
        L.pop();

        R.push(x);
        L.push(R.top());
        R.pop();
    }

    void push(T x){
        L.push(x);
        R.push(L.top());
        L.pop();
        L.push(R.top());
        R.pop();

        if(L.size()>R.size()+1){
            R.push(L.top());
            L.pop();
        }
    }

    void pop(){
        if(L.size()+R.size()==0) return;

        L.pop();
        if(L.size()<R.size()){
            L.push(R.top());
            R.pop();
        }
    }

    pair<T,T> top()const{
        return make_pair(L.top(), R.top());
    }

    size_t size()const{
        return L.size()+R.size();
    }

    bool empty()const{
        return (L.empty()||R.empty());
    }

    // MiddleQueue<ll> que(-LINF, LINF);
    // que.push(a);
    // que.push2(a);
    // que.pop();
    // pair<ll,ll> p = que.top();
    // ABC127F

};

