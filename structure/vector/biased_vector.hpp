#pragma once

template <typename T>
class biased_vector:public vector<T>{
public:
   biased_vector(size_t n):vector<T>(n){}
   biased_vector(size_t n, const T& a):vector<T>(n, a){}
   int b = 0;
   void setB(int b_){
      b = b_;
   }

   const T& operator[](int i)const{
      return (this->begin()[i-b]);
   }

   T& operator[](int i){
      return (this->begin()[i-b]);
   }
};