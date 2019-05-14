#include <set> 
#include <vector>
#include <cmath>
#include <iostream>
namespace itertools
{
template <typename T>
    
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &S)
{
    stream << "{";

    auto temp = S.begin();
    if(temp != S.end())
    { 
        stream << *temp; 
        ++temp;
    }

    while (temp != S.end())
    {
        stream << ',' << *temp;
        ++temp;
    }

    stream << "}";

    return stream;
}

template <class T>

class _powerset
{

private:
    T _from;
    template <class E>
        
    class iterator
    {

    public:

        E itr_begin;
        E itr_end;
        unsigned int index;
        unsigned int num_of_elements;

        iterator(E itr_start, E itr_fin) : itr_begin(itr_start),
                                                         itr_end(itr_fin),
                                                         index(0),
                                                         num_of_elements(0)
        {
            E element_iterator = itr_begin;
            while (element_iterator != itr_end)
            {
                ++num_of_elements;
                ++element_iterator;
            }

            num_of_elements = std::pow(2, num_of_elements);
        }

        // operators
        bool operator!=(_powerset::iterator<E> const &other) const
        {
            return ((num_of_elements - index) != (other.num_of_elements - other.index - 1));
        }

        auto operator*() const
        {
            E element_iterator = itr_begin;
            std::vector<typename std::remove_const<typename std::remove_reference<decltype(*itr_begin)>::type>::type> S;
           
            unsigned int i = index;
            while (i != 0 && element_iterator != itr_end)
            { 
                unsigned int r = i % 2;
                i = i >> 1; 

                if (r == 1)
                    S.emplace_back(*element_iterator);

                ++element_iterator;
            }

            return S;
        }

        _powerset::iterator<E> &operator++()
        {

            ++index;
            return *this;
        }
    };

public:
    _powerset(T from) : _from(from) {}                                                                                                              // constructor
    auto begin() const { return _powerset::iterator<decltype(_from.begin())>(_from.begin(), _from.end()); } 
    auto end() const { return _powerset::iterator<decltype(_from.begin())>(_from.end(), _from.end()); }       
};                                                                                                                                                  // class

template <typename T>

_powerset<T> powerset(T from)
{
    return _powerset<T>(from);
}

} 
