#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> frequency;
    for (char ch : s)
    {
        frequency[ch]++;
    }

    vector<pair<char, int>> v(frequency.begin(), frequency.end());
    sort(v.begin(), v.end(), [](const pair<char, int> &a, pair<char, int> &b)
         { return a.second > b.second; });

    string ans = "";
    for (auto it : v)
    {
        if (it.second > 1)
        {
            int count = 0;
            while (count < it.second)
            {
                ans += it.first;
                count++;
            }
        }
        else
            ans += it.first;
    }
    return ans;
}

int main()
{
    string s = "Aabb";
    cout << frequencySort(s) << endl;
}