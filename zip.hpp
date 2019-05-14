#include <utility> // pair
#include <iostream>


namespace itertools
{
// C++ template to print pair<> 
// class by using template 
template <typename T,typename E>
std::ostream &operator<<(std::ostream &os, const std::pair<T,E>&p)
{
    os << p.first << ',' << p.second;

    return os;
}



template <class T, class E>
/*
* _zip class, using two iteratables to iterate over them in pairs (I.E returns elements of type std::pair<T,E>).
* the values given to the constructor must be a iteratable objects (implementing begin() and end() functions).
* and an iterator (ofcourse) which implements the following operators: != (not equal), ++ (prefix increment).
* the _zip class contains inner iterator.
* Note: calling the zip(T,E) function instead of the class _zip is recommended.
*/
class _zip
{
    // Private variables and methods
private:
    T _iteratable_A;    // first iteratable - should be an iteratable
    E _iteratable_B;    // second iteratable - should be an iteratable

    // Inner class (iterator)
    template <typename U, typename V>
    class iterator
    {
    public:
        // variables
        U _iterator_A; //  should be an iterator
        V _iterator_B; //  should be an iterator

        //constructor
        iterator(U iteratable_A, V iteratable_B) : _iterator_A(iteratable_A), _iterator_B(iteratable_B) {}

        // operators
        bool operator!=(_zip::iterator<U,V> const &other) 
        {
            return (_iterator_A != other._iterator_A) && (_iterator_B != other._iterator_B);
        }

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
/*
* zip function, use in loops to iterate over two iteratables.
* Example use case: 
* for(std::pair<char,char> p : zip(range('A','E'), string("niko")))
*   // do somethin...
*/
_zip<T, E> zip(T first, E second)
{
    return _zip<T, E>(first, second);
}

} // namespace itertools