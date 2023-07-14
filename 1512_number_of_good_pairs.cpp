#include <iostream>
#include <vector>
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    int frequency[101] = {0};
    for (int i : nums)
    {
        frequency[i]++;
    }
    int totalPairs = 0;
    for (auto i : frequency)
    {
        totalPairs += (i * (i - 1)) / 2;
    }
    return totalPairs;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << "Total good pairs possile is : " << numIdenticalPairs(nums) << endl;
}