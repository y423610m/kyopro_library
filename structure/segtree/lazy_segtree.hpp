#pragma once

#include <vector>

#define EL(var) cerr << #var << ": " << var << endl;

template <
    typename S,
    S (*Operation)(S, S),
    S (*GetE)(), typename F,
    S (*Mapping)(F, S),
    F (*Convolution)(F, F),
    F (*GetId)()
> 
class LazySegtree
{
public:
    LazySegtree(int n) : _n(n)
    {
        _size = 1;
        _depth = 1;
        while(_size<=_n) {
            _size <<= 1;
            _depth++;
        }
        EL(_size)
        _data.resize(_size*2, GetE());
        _lazyFunc.resize(_size, GetId());
    }

    void Set(int idx, S value)
    {
        idx += _size;
        _data[idx] = value;
        for(int i=_depth; i>=1; i--) {
            _Propagate(idx >> i);
        }
        _data[idx] = value;
        for(int i=1; i<=_depth; i++) {
            _Merge(idx >> i);
        }
    }

    void Apply(int leftIdx, int rightIdx, F f)
    {
        if( leftIdx == rightIdx ) {
            return;
        }

        leftIdx += _size; rightIdx += _size;
        for (int i = _depth; i >= 1; i--) {
            if (((leftIdx >> i) << i) != leftIdx) _Propagate(leftIdx >> i);
            if (((rightIdx >> i) << i) != rightIdx) _Propagate((rightIdx - 1) >> i);
        }

        {
            int l = leftIdx, r = rightIdx;
            while (l < r) {
                if (l & 1) _PropagateEval(l++, f);
                if (r & 1) _PropagateEval(--r, f);
                l >>= 1;
                r >>= 1;
            }
        }

        for (int i = 1; i<=_depth; i++) {
            if (((leftIdx >> i) << i) != leftIdx) _Merge(leftIdx >> i);
            if (((rightIdx >> i) << i) != rightIdx) _Merge((rightIdx - 1) >> i);
        }
    }

    S Product(int leftIdx, int rightIdx)
    {
        if ( leftIdx == rightIdx ) return GetE();

        leftIdx += _size;
        rightIdx += _size;

        for (int i = _depth; i >= 1; i--) {
            if (((leftIdx >> i) << i) != leftIdx) _Propagate(leftIdx >> i);
            if (((rightIdx >> i) << i) != rightIdx) _Propagate((rightIdx - 1) >> i);
        }

        S l = GetE(), r = GetE();
        while (leftIdx < rightIdx) {
            if (leftIdx & 1) l = Operation(l, _data[leftIdx++]);
            if (rightIdx & 1) r = Operation(_data[--rightIdx], r);
            leftIdx >>= 1;
            rightIdx >>= 1;
        }

        return Operation(l, r);
    }

private:
    void _Merge(int dataIdx)
    {
        _data[dataIdx] = Operation(_data[dataIdx*2], _data[dataIdx*2+1]);
    }

    void _Propagate(int idx)
    {
        _PropagateEval(idx*2, _lazyFunc[idx]);
        _PropagateEval(idx*2+1, _lazyFunc[idx]);
        _lazyFunc[idx] = GetId();
    }

    void _PropagateEval(int dataIdx, F f)
    {
        _data[dataIdx] = Mapping(f, _data[dataIdx]);
        if (dataIdx < _size) _lazyFunc[dataIdx] = Convolution(f, _lazyFunc[dataIdx]);
    }

private:
    int _n;
    int _size;
    int _depth;
    std::vector<S> _data;
    std::vector<F> _lazyFunc;
};


