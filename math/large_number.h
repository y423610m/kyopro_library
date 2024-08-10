#ifndef __LARGE_NUMBER__
#define __LARGE_NUMBER__


// struct to process large numbers which can exceeds 64 bit
template<typename T>
struct VectorNumber
{

   VectorNumber(){
      vec = {0};
   }

   VectorNumber(const string& s){
      vec.clear();
      vec.reserve(s.size());
      for(int i=s.size()-1;i>=0;i--){
         vec.push_back(s[i]-'0');
      }
   }

   VectorNumber(const vector<T>& v){
      vec = v;
   }
   
   VectorNumber& operator+=(VectorNumber& other){
      for(int i=0; i<other.vec.size(); i++){
         if(other.vec[i]>0){
            while(vec.size()<i+1) vec.push_back(0);
            vec[i] += other.vec[i];
         }
      }
      CarryUp();
      return *this;
   }

   VectorNumber& operator*=(T scale){
      for(int i=0; i<vec.size(); i++){
         vec[i] *= scale;
      }
      CarryUp();
      return *this;
   }

   void CarryUp(){
      for(int i=0; i<vec.size(); i++) if(vec[i]>=10){
         T tmp = vec[i]/10;
         vec[i] %= 10;
         if(vec.size()==i+1){
            vec.push_back(0);
         }
         vec[i+1] += tmp;
      }
      while(vec.size()>1&&vec.back()==0) vec.pop_back();
   }

   bool operator<(const VectorNumber<T>& other) const {
      if( vec.size() < other.vec.size() ) return true;
      if( vec.size() > other.vec.size() ) return false;
      for(int i=vec.size()-1; i>=0; i--){
         if(vec[i] < other.vec[i]) return true;
         if(vec[i] > other.vec[i]) return false;
      }
      return false;
   }

   bool operator>(const VectorNumber<T>& other) const {
      if( vec.size() > other.vec.size() ) return true;
      if( vec.size() < other.vec.size() ) return false;
      for(int i=vec.size()-1; i>=0; i--){
         if(vec[i] > other.vec[i]) return true;
         if(vec[i] < other.vec[i]) return false;
      }
      return false;
   }

   friend ostream& operator<<(ostream& os, const VectorNumber<T>& vn) {
      for(int i=vn.vec.size()-1; i>=0; i--){
         os << vn.vec[i];
      }
      return os;
   }

   vector<ll> vec;
};

/*

   string a,b;
   cin>>a>>b;

   VectorNumber<ll> A(a);
   VectorNumber<ll> B;
   VectorNumber<ll> D(V<ll>{1});

   D *= 2;
   ES(A) EL(B)
   B += D;

PGBattle 2023 mashmallow c

*/



#endif //__LARGE_NUMBER__