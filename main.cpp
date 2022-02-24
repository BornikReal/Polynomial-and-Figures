#include <iostream>
#include <vector>
#include "polynomial/polynomial.h"
#include "figures/figures.h"
using namespace std;

int main(int argc, char* argv[])
{
    vector <Point> a = {Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
    vector <Point> b = {Point(0, 0), Point(3, 0), Point(2, 2), Point(0, 2)};
    Polyline p1(a);
    Polyline p11({a[0], a[2]});
    Polyline p12({a[2], a[3]});
    cout << p11.collinear(p12) << endl;
    ClosedPolyline p2(a);
    Polygon p3(a);
    RegularPolygon p4(a);
    Triangle p5(a);
    Trapezoid p6(a);
    Trapezoid p7(b);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    cout << p5 << endl;
    cout << p6 << endl;
    cout << p7 << endl;
    return 0;
}