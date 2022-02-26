#include <iostream>
#include <vector>
#include "polynomial/polynomial.h"
#include "figures/figures.h"
using namespace std;

int main(int argc, char* argv[])
{
    vector <double> x = {-6, 11, -6, 1};
    vector <double> y = {2, 0, 1};
    Polynimial t(x);
    Polynimial t1(y);
    cout << t << endl;
    cout << t1 << endl;
    cout << t.root(0, 4, 0.001) << endl;
    cout << t1.root(-4, 4, 0.001) << endl;
    cout << t + t1 << endl;
    cout << t * t1 << endl;
    cout << t / t1 << endl;
    cout << t - t1 << endl;
    cin >> t1;
    cout << t1 << endl;

    vector <Point> a = {Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
    vector <Point> b = {Point(0, 0), Point(2, 0), Point(2, 2)};
    vector <Point> c = {Point(0, 0), Point(3, 0), Point(2, 2), Point(0, 2)};
    Polyline p1(a);
    Polyline p11({a[0], a[2]});
    Polyline p12({a[2], a[3]});
    cout << p11.collinear(p12) << endl;
    ClosedPolyline p2(a);
    cout << p2 << endl;
    vector<Polygon> figures;
    Polygon p3(a);
    RegularPolygon p4(a);
    Triangle p5(b);
    Trapezoid p6(c);
    figures.push_back(p3);
    figures.push_back(p4);
    figures.push_back(p5);
    figures.push_back(p6);
    for (int i = 0; i < figures.size(); i++)
        cout << figures[i] << endl;
    return 0;
}