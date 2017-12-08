

template<typename... _Elements>
struct Tuple; 


/**
   * Zero-element tuple implementation. This is the basis case for the 
   * inheritance recursion.
   */

template<>
struct Tuple<>
{
  Tuple() = default;
};

/**
   * Recursive tuple implementation. Here we store the @c Head element
   * and derive from a @c Tuple_impl containing the remaining elements
   * (which contains the @c Tail).
   */

template<typename T, typename... Tail> 
struct Tuple<T, Tail...> : public Tuple<Tail...>
{
    T x;
    using Base = Tuple<Tail...>;
    Base* base() { return static_cast<Base*>(this); }
    const Base* base() const { return static_cast<const Base*>(this); }
    explicit constexpr Tuple(const T & __head, const Tail&... __elements) : Base(__elements...), x(__head) { }
}; 


/* print API : */

#include <iostream>


template<typename... types>
void print_elements(std::ostream& os, const Tuple<types...>& t);


template<>
void print_elements(std::ostream& os, const Tuple<>& t)
{
    os << " ";
}

template<typename T, typename... types>
void print_elements(std::ostream& os, const Tuple<T, types...>& t)
{
    os << t.x << ", ";
    print_elements(os, *t.base());
}



template<typename... types>
std::ostream& operator<<(std::ostream& os, const Tuple<types...>& t);

template<>
std::ostream& operator<<(std::ostream& os, const Tuple<>& t)
{
    os << "{ }";
    return os;
}


template<typename T, typename... types>
std::ostream& operator<<(std::ostream& os, const Tuple<T, types...>& t)
{
    os << "{ ";
    print_elements(os,t);
    os << " }";
    return os;
}


int main () {
    
    Tuple<double, int, char> x {1.1, 42, 'a'};
    std::cout << x << "\n";
    
    std::cout << Tuple<double ,int,int,int>{1.2,3,5,7} << "\n";
    std::cout << Tuple<double ,int,int>{1.2,3,5} << "\n";
    std::cout << Tuple<double ,int>{1.2,3} << "\n";
    std::cout << Tuple<char>{'z'} << "\n";
    std::cout << Tuple<>{} << "\n";
    return 0;
}







