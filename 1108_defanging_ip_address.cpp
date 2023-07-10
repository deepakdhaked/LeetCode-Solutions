#include <iostream>
using namespace std;

string defangIPaddr(string address)
{
    string ans = "";
    for (char ch : address)
    {
        if (ch == '.')
        {
            ans += "[.]";
        }
        else
        {
            ans += ch;
        }
    }
    return ans;
}

int main()
{
    string address = "255.100.50.0";
    cout << defangIPaddr(address) << endl;
}