
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
 
        U itr1; 
        V itr2; 

        bool flag;

        iterator(U first, V second) : itr1(first), itr2(second), flag(true) {}

        bool operator!=(chain::iterator<U,V> const &other) 
        {
            if (flag && !(itr1 != (other.itr1)))
                flag = false;

            if(flag)
                return (itr1 != (other.itr1));
            else 
                return (itr2 != (other.itr2));

            
        }

        decltype(*itr1) operator*() const
        {
            if(flag)
                return *itr1;
            else
                return *itr2;
        }

        chain::iterator<U,V> &operator++()
        {
            if(flag)
                ++itr1;
            else 
                ++itr2;
            
            return *this;
        }
    };

public:
    chain(A from, B to) : first(from), second(to) {} // constructor

    auto begin() const{ 
        return  chain::iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(), second.begin()); }  // iteratable object

    auto end() const {
        return chain::iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end()); }  // iteratable object  
};  // class

template <typename A, typename B>

chain<A, B> mychain(A chain1, B chain2)
{
    return mychain<A, B>(chain1, chain2);
}

} 
