# define kyopro commands here
#

function g() {
    g++ -std=c++23 $1.cpp -I ${MY_KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT}
}

function gon(){
    g++-12 -std=c++23 -I ${MY_KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -O2 -g -DONLINE_JUDGE $1.cpp
}

function gof(){
    g++-12 -std=c++23 -I ${MY_KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -O2 -g $1.cpp
}

function g_past(){
    g++-12 -std=c++23 -I ${MY_KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -g -fsanitize=undefined,address -D_GLIBCXX_DEBUG $1.cpp
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
    oj-bundle -I ${MY_KYOPRO_LIBRARY_ROOT} -I ${MY_ATCODER_LIBRARY_ROOT} -I ${MY_BOOST_LIB_ROOT} -I ${MY_EIGEN_LIB_ROOT} -I /usr/include $1.cpp >${BUNDLE_FILENAME}
    python3 ${MY_KYOPRO_LIBRARY_ROOT}/core/RemoveLine.py        
    code ${BUNDLE_FILENAME}
}

function bd(){
    bundle $1
    acc submit ${BUNDLE_FILENAME}
}

function accr(){
    cd ${MY_ATCODER_ROOT}
    cd $1
    acc new -f $2
    cd $2
}

function ac(){
    cp ${MY_KYOPRO_LIBRARY_ROOT}/core/ac.cpp $1.cpp
    code $1.cpp
}
