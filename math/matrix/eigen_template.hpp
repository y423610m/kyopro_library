#include <Eigen/Core>
#include <Eigen/Dense>
template<typename typeT, int rowN, int colN>
istream &operator>>(istream& is, Eigen::Matrix<typeT, rowN, colN>& M){
   for(int r=0;r<rowN;r++){
      for(int c=0;c<colN;c++){
         is>>M(r,c);
      }
   }
   return is;
}

template<typename typeT>
istream &operator>>(istream& is, Eigen::Matrix<typeT, Eigen::Dynamic, Eigen::Dynamic>& M){
   for(int r=0;r<M.rows();r++){
      for(int c=0;c<M.cols();c++){
         is>>M(r,c);
      }
   }
   return is;
}