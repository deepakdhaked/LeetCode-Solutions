#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Time Complexity : O(N *Log(K)), where K = i0^7
// Space Complexity: O(1)
double timeRequired(vector<int> &dist, int speed)
{
    double time = 0.0;
    for (int i = 0; i < dist.size(); i++)
    {
        double t = (double)dist[i] / (double)speed;
        time += (i == dist.size() - 1 ? t : ceil(t));
    }
    return time;
}

int minSpeedOnTime(vector<int> &dist, double hour)
{
    int start = 1, end = 1e7;
    int minSpeed = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (timeRequired(dist, mid) <= hour)
        {
            minSpeed = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return minSpeed;
}