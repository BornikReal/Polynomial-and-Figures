#include <iostream>
#include <vector>
#include "polynomial/polynomial.h"
#include "figures/figures.h"
using namespace std;

int main(int argc, char* argv[])
{
    vector <double> a = {2, 2, 2};
    Polynimial t(a);
    cout << t << endl;
    cout << t(2) << endl;
    // vector <Point> a = {Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
    // vector <Point> b = {Point(0, 0), Point(2, 0), Point(2, 2)};
    // vector <Point> c = {Point(0, 0), Point(3, 0), Point(2, 2), Point(0, 2)};
    // Polyline p1(a);
    // Polyline p11({a[0], a[2]});
    // Polyline p12({a[2], a[3]});
    // cout << p11.collinear(p12) << endl;
    // ClosedPolyline p2(a);
    // cout << p2 << endl;
    // vector<Polygon> figures;
    // Polygon p3(a);
    // RegularPolygon p4(a);
    // Triangle p5(b);
    // Trapezoid p6(c);
    // figures.push_back(p3);
    // figures.push_back(p4);
    // figures.push_back(p5);
    // figures.push_back(p6);
    // for (int i = 0; i < figures.size(); i++)
    //     cout << figures[i] << endl;
    return 0;
}