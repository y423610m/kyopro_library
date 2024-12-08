# define kyopro commands here
#

function g() {
    g++ -std=c++23 $1.cpp -I ${KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT}
}

function gon(){
    g++-12 -std=c++23 -I ${KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -O2 -g -DONLINE_JUDGE $1.cpp
}

function gof(){
    g++-12 -std=c++23 -I ${KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -O2 -g $1.cpp
}

function g_past(){
    g++-12 -std=c++23 -I ${KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -g -fsanitize=undefined,address -D_GLIBCXX_DEBUG $1.cpp
}

function a(){
    ./a.out
}

function te(){
    oj t -d ./tests/ --ignore-spaces
}

function sb(){
    acc submit $1.cpp
}

BUNDLE_FILENAME=SUB.cpp
function bundle(){
    oj-bundle -I ${KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -I /usr/include $1.cpp >${BUNDLE_FILENAME}
    python3 ${KYOPRO_LIBRARY_ROOT}/core/RemoveLine.py        
    code ${BUNDLE_FILENAME}
}

function bd(){
    bundle $1
    acc submit ${BUNDLE_FILENAME}
}
