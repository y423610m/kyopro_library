#pragma once

struct MyHash{
    //arr: 0=c++hash 1=rand() 2=(1+a)*(2*a+1)*()
    array<size_t,3> arr;
    MyHash(){
        arr.fill(0);
    }

    bool operator==(MyHash a){
        for(int i=0;i<3;i++) if(arr[i]!=a.arr[i]) return false;
        return true;
    }

    size_t& operator[](int i){
        return arr[i];
    }

    MyHash operator^(MyHash a){
        MyHash ret;
        for(int i=0;i<3;i++) ret[i] = arr[i]^a.arr[i];
        return ret;
    }
};

struct Random{
    const unsigned SEED;
    mt19937 engine;
    unsigned long long mod=0;

    Random(): SEED(random_device()()), engine(SEED) {}
    Random(unsigned long long mod_): SEED(random_device()()), engine(SEED), mod(mod_) {}
    unsigned operator()(){return (mod? engine()%mod: engine());}
//    Random rand;
//    cout<<rand()<<endl;
//    Random mrand(MOD); //->mod rand
//    cout<<mrand()<<endl;
};

template <typename T>
struct MyHashGenerator{
    unordered_map<T,size_t> mp;
    Random rnd;
    const size_t mod_ = 998244353;

    MyHashGenerator(int N){
        mp.reserve(N);
    }

    MyHash get(T a){
        MyHash ret;
        ret[0] = hash<T>()(a);
        if(!mp.count(a)) mp[a] = rnd();
        ret[1] = mp[a];
        a %= mod_;
        ret[2] = a * (a+1346) % mod_ * (a+9185) % mod_;
        return ret;
    }
    /*
    MyHashGenerator<ll> gen(3*N);
    MyHash h = gen.get(a);
    h = h ^ gen.hash(b);
    if(h==gen.hash(a)){}
	c++hash, mtrnd(), a*(a+1346)*(a*9185)%998244353
    */
};