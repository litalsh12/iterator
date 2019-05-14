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
    T _iteratable_A;   
    E _iteratable_B; 
  
    template <typename U, typename V>
    class iterator
    {
    public:
        U _iterator_A;
        V _iterator_B; 

      iterator(U iteratable_A, V iteratable_B) : _iterator_A(iteratable_A), _iterator_B(iteratable_B) {}

        bool operator!=(_zip::iterator<U,V> const &other) {return (_iterator_A != other._iterator_A) && (_iterator_B != other._iterator_B);}

        std::pair<decltype(*_iterator_A),decltype(*_iterator_B)> operator*() const
        {
            return std::pair< decltype(*_iterator_A),
                              decltype(*_iterator_B)> (*_iterator_A,*_iterator_B);
        }

        _zip::iterator<U,V> &operator++()
        {
            ++_iterator_A;
            ++_iterator_B;
            
            return *this;
        }
    };

public:
    _zip(T from, E to) : _iteratable_A(from), _iteratable_B(to) {} // constructor

    auto begin() const{ 
        return  _zip::iterator<decltype(_iteratable_A.begin()),decltype(_iteratable_B.begin())>(_iteratable_A.begin(), _iteratable_B.begin()); }  // iteratable object

    auto end() const {
        return _zip::iterator<decltype(_iteratable_A.end()),decltype(_iteratable_B.end())>(_iteratable_A.end(), _iteratable_B.end()); }  // iteratable object  
};  // class

template <typename T, typename E>

_zip<T, E> zip(T first, E second)
{
    return _zip<T, E>(first, second);
}

} 
