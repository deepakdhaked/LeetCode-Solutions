#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    int y = abs(n);
    double ans = 1.0;
    while (y >= 1)
    {
        if (y & 1)
        {
            ans *= x;
        }
        y /= 2;
        x *= x;
    }
    return n < 0 ? 1 / ans : ans;
}