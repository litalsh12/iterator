
namespace itertools
{

template <class A, class B>

class chain
{
   private:
     A first;   
     B second;    
    template <typename U, typename V>
    class iterator
    {
    public:
        U i_1; 
        V i_2; 

        bool f;
        iterator(U first, V second) : i_1(first), i_2(second), f(true) {}
        bool operator!=(chain::iterator<U,V> const &other) 
        {
            if (f && !(i_1 != (other.i_1))){
                f = false;}

            if(f){
                return (i_1 != (other.i_1));}
            else {
                return (i_2 != (other.i_2));}
        }

        decltype(*i_1) operator*() const {
            if(f){return *i_1;}     
            else{ return *i_2;}       
        }

        chain::iterator<U,V> &operator++(){
            if(f){++i_1;}     
            else{++i_2;} 
            return *this;
        }
    };

    public:
          chain(A from, B to) : first(from), second(to) { } 
          auto begin() const{  return  chain::iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(), second.begin()); }  
          auto end() const {   return chain::iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end()); }    
   };  





template <typename A, typename B>

chain<A, B> mychain(A chain_a, B chain_b)
{
    return mychain<A, B>(chain_a, chain_b);
}

} 
