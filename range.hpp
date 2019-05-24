
namespace itertools{

    template <typename T>

    class range{
        private:

        T _first;
        T _last;

        class iterator{
            
            public:
            T value;

            iterator(T v) : value(v){}

            T operator*() const{
                return value;
            }

            iterator& operator++(){
               value++;
               return  *this;
            } 
            iterator operator++ (int){
                iterator temp(*this);
                operator++();
                return temp;
            } 
        
            bool operator!=(iterator const &diff) const{
                return !(value == (diff.value));
            }           
        };
        public:
        range (T start, T end): _first(start), _last(end) {}
        iterator begin() const {return iterator(_first); }  
        iterator end() const { 
            return iterator(_last); } 
    };
}

  