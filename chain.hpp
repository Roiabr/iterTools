#include "iostream"
namespace itertools{
      template <typename T1, typename T2>
      class chain{
           private:
            T1 one;
            T2 two;
            public:
            chain (T1 start, T2 end): one(start), two(end){
            }

        template <typename type1, typename type2>
        class iterator{ 
        private:
            type1 it1;
            type2 it2;
            bool check;

        public:
            iterator(type1 first, type2 second): it1(first), it2(second), check(true){}             
            

            iterator<type1,type2>& operator++(){
               if(this->check==true){
                 ++this->it1;
                }
                else{
                   ++this->it2;
                }
                return  *this;
            }
            iterator operator++ (int){
                iterator temp(*this);
                operator++();
                return temp;
            } 

            decltype(*it1) operator*() const{
                if(this->check==true){
                return *it1;
                }
                else{
                    return *it2;
                }
            }

            bool operator!=(iterator<type1,type2> const &rhs)
             {
               if(this->check && !(this->it1 != (rhs.it1))){
                    this->check=false;
               }

               if(this->check==true){
                return this->it1 != (rhs.it1);
               }
               else{
                   return this->it2 != (rhs.it2);
               }
            }

        };
       
        
        auto begin() const { 
            return iterator<decltype(this->one.begin()),decltype(this->two.begin())>(this->one.begin(),this->two.begin()); 
            }  
        auto end() const { 
            return iterator<decltype(this->one.end()),decltype(this->two.end())>(this->one.end(),this->two.end()); 
             } 
          
      };
}