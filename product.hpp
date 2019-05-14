#include <utility> // pair

namespace itertools
{


template <class T, class E>
/*
* _product class, using two iteratables to iterate over them in pairs (I.E returns elements of type std::pair<T,E>).
* the values given to the constructor must be a iteratable objects (implementing begin() and end() functions).
* and an iterator (ofcourse) which implements the following operators: != (not equal), ++ (prefix increment).
* the _product class contains inner iterator.
* Note: calling the product(T,E) function instead of the class _product is recommended.
*/
class _product
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

        V _iterator_B_start_pos; //  should be an iterator

        //constructor
        iterator(U iteratable_A, V iteratable_B) : 
            _iterator_A(iteratable_A), 
            _iterator_B(iteratable_B),
            _iterator_B_start_pos(iteratable_B) {}

        // operators
        bool operator!=(_product::iterator<U,V> const &other) 
        {            
            // if iterator A hasn't finish yet, and B finished, then rewind B to the start.
            if ((_iterator_A != other._iterator_A) && !(_iterator_B != other._iterator_B))
            { // rewind B
                _iterator_B = _iterator_B_start_pos;
                ++_iterator_A;
            }

            return (_iterator_A != other._iterator_A);
        }

        std::pair<decltype(*_iterator_A),decltype(*_iterator_B)> operator*() const
        {
            return std::pair< decltype(*_iterator_A),
                              decltype(*_iterator_B)> (*_iterator_A,*_iterator_B);
        }

        _product::iterator<U,V> &operator++()
        {
            ++_iterator_B;
            return *this;
        }
    };

public:
    _product(T from, E to) : _iteratable_A(from), _iteratable_B(to) {} // constructor

    auto begin() const{ 
        return  _product::iterator<decltype(_iteratable_A.begin()),decltype(_iteratable_B.begin())>(_iteratable_A.begin(), _iteratable_B.begin()); }  // iteratable object

    auto end() const {
        return _product::iterator<decltype(_iteratable_A.end()),decltype(_iteratable_B.end())>(_iteratable_A.end(), _iteratable_B.end()); }  // iteratable object  
};  // class

template <typename T, typename E>
/*
* product function, use in loops to iterate over two iteratables in set-product-like scheme.
* Example use case: 
* for(std::pair<char,char> p : product(range('A','E'), string("niko")))
*   // do somethin...
*/
_product<T, E> product(T first, E second)
{
    return _product<T, E>(first, second);
}

} // namespace itertools