#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../../math/matrix/matrix.hpp"

int main() {
    Matrix<int> mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    
    Matrix<int> mat2 = mat;
    mat2 += mat;
    assert(mat2[0][0] == 2);
    assert(mat2[1][1] == 8);
    
    Matrix<int> mat3 = mat * mat;
    assert(mat3[0][0] == 7);
    assert(mat3[0][1] == 10);
    assert(mat3[1][0] == 15);
    assert(mat3[1][1] == 22);
    
    Matrix<int> mat4 = Matrix<int>::I(2);
    assert(mat4[0][0] == 1);
    assert(mat4[0][1] == 0);
    
    Matrix<int> mat5 = mat ^ 2;
    assert(mat5[0][0] == mat3[0][0]);
    assert(mat5[1][1] == mat3[1][1]);
    
    cout << "Matrix test passed!" << endl;
    return 0;
}
