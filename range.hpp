namespace itertools
{

template <class T>

class range
{

private:
    T start;
    T end;  

    class iterator
    {

    public:
        T val;
        iterator(T itr) : val(itr){}

        bool operator!=(range::iterator const &other) const
        { 
            return val!=(other.val);
        }
        T operator*() const
        {
            return val;
        }
        range::iterator &operator++()
        {
            ++val;
            return *this;
        }};
public:
    range(T from, T to) : start(from), end(to) {
     }                     
    range::iterator begin() const { 
       return range::iterator(start); 
     } 
    range::iterator end() const { 
         return range::iterator(end); 
     }      
}; 

    
template <typename T>

range<T> myrange(T from, T to)
{
    return range<T>(from, to);
}

} 
