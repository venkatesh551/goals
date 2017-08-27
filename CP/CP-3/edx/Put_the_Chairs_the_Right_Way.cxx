#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>  
#include <iomanip>

struct Point{
    double x;
    double y;
    Point (double x1, double y1) : x(x1), y(y1) {}
};

double euclidianDistance(const Point &a, const Point &b)
{
    double temp = (a.x - b.x) * (a.x - b.x)  + 
                      (a.y - b.y) * (a.y - b.y);
    return std::sqrt(temp);
}

Point findThirdPoint(int a, int b, int c)
{
    double y = (c * c + a * a - b * b) / (2.0 * a);
    double x = std::sqrt(c * c - y * y);
    return Point(x, y);
}

Point getMidPoint(const Point &p, const Point &q)
{
    return Point((p.x + q.x)/2.0, (p.y + q.y)/2.0);
}

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int a, b, c;

    ifs >> a >> b >> c;
    
    Point p1(0, 0), p2(0, a);
    Point p3 = findThirdPoint(a, b, c);
    Point mid1 = getMidPoint(p1, p2);
    Point mid2 = getMidPoint(p1, p3);
    Point mid3 = getMidPoint(p2, p3);
    double totalDistance =  euclidianDistance(mid1, mid2) + 
                  euclidianDistance(mid2, mid3) +
                  euclidianDistance(mid1, mid3);       
    
    ofs.setf(std::ios_base::fixed);
    ofs << std::setprecision(10) << totalDistance/3.0 << std::endl;
    return 0;
}

