#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// first method Time Complexity : O(N^2)
vector<int> twoSum1(vector<int> &nums, int target)
{
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                v.push_back(i);
                v.push_back(j);
            }
        }
    }
    return v;
}

// second method Time Complexity : O(N)
//               Space Complexity : O(N)
vector<int> twoSum2(vector<int> &nums, int target)
{
    vector<int> v;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            v.push_back(m[target - nums[i]]);
            v.push_back(i);
            return v;
        }
        m[nums[i]] = i;
    }
    return v;
}
