#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x,y;
};

double polygonArea(Point *p, int n)
{
    // Initialze area
    double area = 0.0;
 
    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (p[j].x + p[i].x) * (p[j].y - p[i].y);
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area / 2.0);
}

double area(Point *p,int n)
{
    double Area = 0;

    for(int i = 1; i < n-1; i++)
    {
        double x1 = p[i].x - p[0].x;
        double y1 = p[i].y - p[0].y;

        double x2 = p[i+1].x - p[0].x;
        double y2 = p[i+1].y - p[0].y;

        double crossProduct = x1*y2 - x2*y1;

        Area += crossProduct;
    }

    return abs(Area/2.0);
}

int main()
{
    int n;
    cin >> n;

    Point *p = new Point[n];
    for(int i = 0; i < n; i++)
        cin >> p[i].x;

    for(int i = 0; i < n; i++)
        cin >> p[i].y;
    
    cout << polygonArea(p,n) << endl;
    return 0;
}