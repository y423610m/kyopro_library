template <typename T>
struct LIS{
    size_t sz = 0;
    T example;
    vector<int> example_ids;
    vector<int> ids;
    vector<int> from;
    LIS(const T& A, bool strict)
    :from(A.size(), -1)
    {
        T B;
        auto it = B.end();
        for(int i=0;i<A.size();i++){
            if(strict) it = lower_bound(B.begin(), B.end(), A[i]);
            else       it = upper_bound(B.begin(), B.end(), A[i]);
            if(it==B.end()){
                B.push_back(A[i]);
                if(B.size()>1) from[i] = ids.back();
                ids.emplace_back(i);
            }
            else{
                int id = it-B.begin();
                B[id] = A[i];
                ids[id] = i;
                if(id) from[i] = ids[id-1];
            }
            // EL(B)
            // EL(ids)
            // EL(from)
        }
        sz = B.size();

        if(B.size()==0) return;
        int id = ids.back();
        while(id!=-1){
            example.push_back(A[id]);
            example_ids.emplace_back(id);
            id = from[id];
        }
        reverse(example.begin(), example.end());
        reverse(example_ids.begin(), example_ids.end());
    }

    size_t size(){return sz;}

    // vector<int> A = {1,2,3,2,1};
    // LIS lis(A, true);
    // EL(lis.size())
    // EL(lis.example)
    // EL(lis.example_ids)

    // string s = "12321";
    // LIS lis2(s, true);
    // EL(lis2.example)
};

