#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity : O(m*Log(K)), where K = maximum power of one battery, m = size of battries array
// Space Complexity: O(1)
long long maxRunTime(int n, vector<int> &batteries)
{
    long long sum = 0;
    for (int i : batteries)
    {
        sum += i;
    }

    long long start = *min_element(batteries.begin(), batteries.end()), end = sum / n;

    while (start < end)
    {
        long long mid = end - (end - start) / 2;
        long long extra = 0;
        for (int power : batteries)
        {
            extra += min((long long)power, mid);
        }

        if (extra >= (long long)(n * mid))
        {
            start = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}