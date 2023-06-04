#pragma once

template<typename Iter, typename Compare>
int bubble_sort(Iter first, Iter last, Compare cmp){
    int ret = 0;
    if(last-first<=1) return ret;
    for(auto itl = first; itl!=last; itl++){
        for(auto itr = last-1; itr>itl;itr--){
            if(cmp(*itr, *prev(itr))){
                iter_swap(itr, prev(itr));
                ret++;
            }
        }
    }
    return ret;
}

template<typename Iter>
int bubble_sort(Iter first, Iter last){
    return bubble_sort(first, last, std::less<typename std::iterator_traits<Iter>::value_type>());
}

/*
    #include "sort/bubble_sort.hpp"
    vector<ll> A = {3,1,4,1,5,9,2};
    int cnt = bubble_sort(A.begin(), A.end());
    cnt = bubble_sort(A.begin(), A.end(), [](auto a, auto b){return a<b;});
    cnt = bubble_sort(A.begin(), A.end(), greater<>());
    PL(cnt)
    PL(A)
*/