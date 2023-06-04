#pragma once

template<typename T>//modint
struct DynamicRollingHash{
    T hash = 0;
    ll b = 11;
    vector<T> pow;
    deque<ll> A;
    DynamicRollingHash(ll base):b(base),pow(1,T(1)){}

    void push_back(ll a){
        hash *= b;
        hash += a;
        A.push_back(a);
    }
    void pop_back(){
        hash -= A.back();
        hash /= b;
        A.pop_back();
    }
    void push_front(ll a){
        _expand(A.size());
        hash += pow[A.size()]*a;
        A.push_front(a);
    }
    void pop_front(){
        _expand(A.size()-1);
        hash -= pow[A.size()-1]*A.front();
        A.pop_front();
    }
    ll front(){
        return A.front();
    }
    ll back(){
        return A.back();
    }
    ll get(size_t i){
        return A[i];
    }
    void set(size_t i, ll a){
        //assert(A.size()-1-i>=0);
        _expand(A.size()-1-i);
        T p = pow[A.size()-1-i];
        hash -= p*A[i];
        A[i] = a;
        hash += p*a;
    }
    ll val()const{
        return hash.val();
    }
    void _expand(size_t sz){
        while(pow.size()<sz+1) pow.push_back(pow.back()*b);
    }
    void print(){
        for(int i=0;i<A.size();i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    ll operator[](size_t i)const{
        return A[i];
    }
    bool operator==(const DynamicRollingHash& drh){
        return hash.val()==drh.hash.val();
    }
    /*
    DynamicRollingHash<mint> drh(11);//基底
    drh.push_back('a');
    drh.push_front(1);
    drh.pop_back(99);
    drh.pop_front(10);
    drh[0];
    drh.set(i,7);
    rdh.hash, rdh.val();
    if(rd1==rdh2){

    }

    hash = A[0]*b^3 + A[1]*b^2 + A[2]*b^1 + A[3];
    */
};