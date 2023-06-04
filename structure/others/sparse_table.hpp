#pragma once

template< typename T, typename F >
struct SparseTable {
  F f;
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable() = default;

  explicit SparseTable(const vector< T > &v, const F &f) : f(f) {
    const int n = (int) v.size();
    const int b = 32 - __builtin_clz(n);
    //st[i][j]:=長さ1<<iで左端がjである区間のf(l,r);
    st.assign(b, vector< T >(n));
    //長さ1のとき，値は入力
    for(int i = 0; i < int(v.size()); i++) {
      st[0][i] = v[i];
    }
    //長さ1<<iの区間は，長さが1<<(i-1)で，左端がjとj+1<<(i-1)のf()
    // [j, j+1<<(i-1)) と[j+1<<(i-1), j+1<<i)
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    //半開区間なのでv.size()+1
    //lookup[0]=0:l==rのとき，b=?
    //lookup[1]=0:l+1==rのとき，b=0
    //lookup[2]=1:l+2==rのとき，b=1
    lookup.resize(v.size() + 1);
    for(int i = 2; i < int(lookup.size()); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T fold(int l, int r) const {
    int b = lookup[r - l];
    // [l, l+1<<b), [r-1<<b, r)
    return f(st[b][l], st[b][r - (1 << b)]);
  }
};

template< typename T, typename F >
SparseTable< T, F > get_sparse_table(const vector< T > &v, const F &f) {
  return SparseTable< T, F >(v, f);
}

/*
int op(const int& a, const int& b){
    return max(a,b);
}

    int N = 10;
    vector<int> A(N);
    for(int i=0;i<N;i++) A[i] = i;
    SparseTable st(A, &op);
    //auto st = get_sparse_table(A, &op);
    int l = 3, r = 7;
    EL(st.fold(l,r))

ABC282F参照
*/