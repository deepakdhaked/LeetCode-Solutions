#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<double> convertTemperature(double celsius)
{
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius * 1.80 + 32.00;
    vector<double> ans;
    ans.push_back(kelvin);
    ans.push_back(fahrenheit);
    return ans;
}

int main()
{
    double celsius = 32;
    vector<double> res = convertTemperature(celsius);
    cout << "Kelvin : " << res[0] << endl;
    cout << "Fahrenheit : " << res[1] << endl;
}