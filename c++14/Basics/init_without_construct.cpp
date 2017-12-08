#include <iostream>

struct Work {
    std::string author;
    std::string name;
    int year;
};


int main() 
{

    Work s9 { "Beethoven", 
              "Symphony No. 9 in D minor, Op. 125; Choral",
              1824 };
    Work currently_playing { s9 }; // copy initialization
    Work none {}; // default initialization

    std::cout << none.author << ":" << none.name << ":"
              << none.year << std::endl;
    double x{};
    std::cout << x << std::endl;
    Work testObj;
    std::cout << testObj.author << "*" << testObj.name << "*"
              << testObj.year << std::endl;
    return 0;
}
