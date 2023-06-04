#pragma once

template<typename Iter, typename Compare, typename Iter2>
ll merge(Iter first, Iter mid, Iter last, Compare cmp, Iter2 arr){
    ll ret = 0;
    Iter l = first, r = mid;
    Iter2 p = arr;
    while(l<mid&&r<last){
        if(cmp(*r,*l)){
            *p++ = *r++;
            ret += mid - l;
        }
        else{
            *p++ = *l++;
        }
    }
    // ret += mid - l;
    while(l<mid) *p++ = *l++;
    while(r<last) *p++ = *r++;
    for(Iter it = first; it!=last; it++) *it = arr[it-first];
    return ret;
}
 
template<typename Iter, typename Compare, typename Iter2>
ll merge_sort_(Iter first, Iter last, Compare cmp, Iter2 arr){
    ll ret = 0;
    if(last==first) return ret;
    Iter mid = first + (last - first)/2;
    if(first+1<mid) ret += merge_sort_(first, mid, cmp, arr);
    if(mid+1<last) ret += merge_sort_(mid, last, cmp, arr);
    ret += merge(first, mid, last, cmp, arr);
    return ret;
}

template<typename Iter, typename Compare>
ll merge_sort(Iter first, Iter last, Compare cmp){
    vector<typename Iter::value_type> Arr(last-first);
    return merge_sort_(first, last, cmp, Arr.begin());
}
 
template<typename Iter>
ll merge_sort(Iter first, Iter last){
    vector<typename Iter::value_type> Arr(last-first);
    return merge_sort_(first, last, std::less<typename std::iterator_traits<Iter>::value_type>(), Arr.begin());
}

// template<typename Iter, typename Compare, typename Iter2>
// void merge(Iter first, Iter mid, Iter last, Compare cmp, Iter2 arr){
//     Iter l = first, r = mid;
//     Iter2 p = arr;
//     while(l<mid&&r<last){
//         if(cmp(*l,*r)) *p++ = *l++;
//         else *p++ = *r++;
//         // p++;
//     }
//     while(l<mid) *p++ = *l++;
//     while(r<last) *p++ = *r++;
//     for(Iter it = first; it!=last; it++) *it = arr[it-first];
// }
 
// template<typename Iter, typename Compare, typename Iter2>
// void merge_sort_(Iter first, Iter last, Compare cmp, Iter2 arr){
//     if(last==first) return;
//     Iter mid = first + (last - first)/2;
//     if(first+1<mid) merge_sort_(first, mid, cmp, arr);
//     if(mid+1<last) merge_sort_(mid, last, cmp, arr);
//     merge(first, mid, last, cmp, arr);
// }

// template<typename Iter, typename Compare>
// void merge_sort(Iter first, Iter last, Compare cmp){
//     vector<typename Iter::value_type> Arr(last-first);
//     merge_sort_(first, last, cmp, Arr.begin());
// }
 
// template<typename Iter>
// void merge_sort(Iter first, Iter last){
//     vector<typename Iter::value_type> Arr(last-first);
//     merge_sort_(first, last, std::less<typename std::iterator_traits<Iter>::value_type>(), Arr.begin());
// }

/*
    #include "sort/bubble_sort.hpp"
    vector<ll> A = {3,1,4,1,5,9,2};
    int cnt = bubble_sort(A.begin(), A.end());
    cnt = bubble_sort(A.begin(), A.end(), [](auto a, auto b){return a<b;});
    cnt = bubble_sort(A.begin(), A.end(), greater<>());
    PL(cnt)
    PL(A)
*/