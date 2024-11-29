#pragma once

#include <vector>

template <typename S, S (*operation)(S, S), S(*e)()>
class SegmentTree
{
public:
    SegmentTree(int n) : _n(n)
    {
        _size = 1;
        _depth = 1;
        while( _size < _n ) {
            _size <<= 1;
            _depth++;
        }
        _data.assign(_size*2, e());
    }

    void Set(int idx, S value)
    {
        assert(0<=idx && idx<_n);
        idx += _size;
        _data[idx] = value;
        for(int i=1; i<_depth; i++) _Merge(idx>>i); 
    }

    S Get(int idx)
    {
        assert(0<=idx && idx<_n);
        return _data[_size+idx];
    }

    S Product(int leftIdx, int rightIdx)
    {
        S l = e(), r = e();
        leftIdx += _size, rightIdx += _size;
        while(leftIdx<rightIdx) {
            if(leftIdx&1) l = operation(l, _data[leftIdx++]);
            if(rightIdx&1) r = operation(_data[--rightIdx], r);
            leftIdx >>= 1;
            rightIdx >>= 1;
        }
        return operation(l, r);
    }

    void _Merge(int idx)
    {
        _data[idx] = operation(_data[idx*2], _data[idx*2+1]);
    }

private:
    int _n;
    int _size;
    int _depth;
    std::vector<S> _data;
};

