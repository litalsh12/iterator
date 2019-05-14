#include <utility> 
#include <iostream>


namespace itertools
{

template <typename T,typename E>
std::ostream &operator<<(std::ostream &os, const std::pair<T,E>&p)
{
    os << p.first << ',' << p.second;

    return os;
}



template <class T, class E>

class _zip
{
    
private:
    T iter_a;    
    E iter_b;  

    
    template <typename U, typename V>
    class iterator
    {
    public:
       
        U iter_1;
        V iter_2; 

       
        iterator(U iter_a, V iter_b) : iter_1(iter_a), iter_2(iter_b) {}

        
        bool operator!=(_zip::iterator<U,V> const &other) {
        
            return (iter_1 != other.iter_1) && (iter_2 != iter_2);
        }

        std::pair<decltype(*iter_2),decltype(*iter_2)> operator*() const{
        
            return std::pair< decltype(*iter_1),
                              decltype(*iter_2)> (*iter_1,*iter_2);
        }

        _zip::iterator<U,V> &operator++(){
        
            ++iter_1;
            ++iter_2;
            
            return *this;
        }
    };

public:
    _zip(T from, E to) : first(from), second(to) {} 

    auto begin() const{ 
        return  _zip::iterator<decltype(iter_a.begin()),decltype(iter_b.begin())>(iter_a.begin(), iter_b.begin()); }  

    auto end() const {
        return _zip::iterator<decltype(iter_a.end()),decltype(iter_b.end())>(iter_a.end(), iter_b.end()); }  
};  



template <typename T, typename E>
_zip<T, E> zip(T f, E s){
    return _zip<T, E>(f, s);
}

} 

