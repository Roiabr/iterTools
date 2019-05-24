#include <iostream>
using namespace std;


namespace itertools{
    template<typename T,typename G>
    class product 
    {   
        private:
         T first; // range 1
         G second; // range 2
         public:
        product(){}
        
        product(const T& it1, const G& it2): first(it1),second(it2){}
        template <typename type1, typename type2>
         class iterator
        {
        private:
        type1 it1;
        type2 it2;
        type2 begin2;

        public:
         bool TorF;

            iterator(type1 firstIT, type2 secondIT): it1(firstIT), it2(secondIT),begin2(secondIT),TorF(false){}             
            iterator<type1,type2>& operator++()
            {     
                ++this->it2;
                return  *this;
            }
             pair <decltype(*it1),decltype(*it2)> operator*() const
             {
                return pair <decltype(*it1),decltype(*it2)>(*it1,*it2);
             }
            bool operator!=(iterator<type1,type2> const &rhs)
             {  
                  if(!(this->it2 != rhs.it2) && (this->it1 != rhs.it1))
                 {      ++this->it1;
                        this->it2=this->begin2;
                 }
                  if(!(this->it1 != rhs.it1))
                 {
                     return false;
                 }
                 return true;
                  
                     
             }
        };
        auto begin() const { 
            return iterator<decltype(this->first.begin()),decltype(this->second.begin())>(this->first.begin(),this->second.begin()); 
            }  
        auto end() const { 
            return iterator<decltype(this->first.end()),decltype(this->second.end())>(this->first.end(),this->second.end()); 
             }
    
        
        };
        
        

}