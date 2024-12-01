# define kyopro commands here
#

function g() {
    g++ -std=c++23 $1.cpp -I ${KYOPRO_LIBRARY_ROOT}
}

