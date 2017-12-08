
#include <iostream>

struct Date{

    int d;
    int m;
    int y;

    // explicit Date(int day) : d(day){}
    // Date(int day, int month) : d(day), m(month){}
    Date(int day) : d(day){m = 0; y = 0;}
    Date(const Date &that) {
        std::cout  <<  "Copy CTR "  << std::endl;
        d = that.d;
        m = that.m;
        y = that.y;
    }

};


void printDate(const Date &dt) {

    std::cout  << dt.d << " " << dt.m << " " << dt.y << std::endl;
}

int main()
{

    Date d = 5;
    // Date d = {5, 12};
    printDate(d);
    Date d1{d};
    printDate(d1);

    return 0;
}
