
#include <iostream>

struct Date{

    int d;
    int m;
    int y;

    // explicit Date(int day) : d(day){}
    // Date(int day, int month) : d(day), m(month){}
    Date(int day) : d(day){}

};


void printDate(const Date &dt) {

    std::cout  << dt.d << " " << dt.m << " " << dt.y << std::endl;
}

int main()
{

    Date d = 5;
    // Date d = {5, 12};
    printDate(d);

    return 0;
}
