#include <iostream>
using namespace std;

int largestVariance(string s)
{
    int frequencyHash[26] = {0};
    for (char ch : s)
    {
        frequencyHash[ch - 'a']++;
    }
    int globalMax = 0;
    for (int i = 0; i < 26; i++)
    {
        if (frequencyHash[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < 26; j++)
        {
            if (i == j || frequencyHash[j] == 0)
            {
                continue;
            }
            char major = 'a' + i;
            char minor = 'a' + j;
            int majorCount = 0, minorCount = 0, restMinor = frequencyHash[j];

            for (char ch : s)
            {
                if (ch == major)
                {
                    majorCount++;
                }
                if (ch == minor)
                {
                    minorCount++;
                    restMinor--;
                }
                if (minorCount > 0)
                {
                    globalMax = max(globalMax, majorCount - minorCount);
                }
                if (majorCount < minorCount && restMinor > 0)
                {
                    majorCount = 0;
                    minorCount = 0;
                }
            }
        }
    }
    return globalMax;
}

int main()
{
    string s = "aababbb";
    cout << "Largest substring variance is : " << largestVariance(s) << endl;
}