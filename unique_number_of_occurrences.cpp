#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isFrequencyUnique(int n, int arr[])
{
    unordered_map<int, int> frequency;
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++;
    }
    unordered_set<int> s;
    for (auto i : frequency)
    {
        if (s.find(i.second) != s.end())
        {
            return false;
        }
        s.insert(i.second);
    }
    return true;
}

int main()
{
    int arr[] = {1, 1, 2, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isFrequencyUnique(n, arr) == true)
    {
        cout << "Unique" << endl;
    }
    else
    {
        cout << "Not Unique" << endl;
    }
}