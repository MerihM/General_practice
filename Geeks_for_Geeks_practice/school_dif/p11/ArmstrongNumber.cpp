//  Complete the function armstrongNumber() which takes n as input
//  parameter and returns "Yes" if it is a armstrong number else returns "No"..
// Armstrong number is a^3 + b^3 + c^3 = abc, where every letter represents digit
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cube(int a)
{
    return a * a * a;
}
string armstrongNumber(int n)
{
    int tempN = n, sum;
    vector<int> tempArr;
    while (tempN > 0)
    {
        tempArr.push_back(tempN % 10);
        tempN /= 10;
    }
    for (int i = 0; i < tempArr.size(); i++)
        sum += cube(tempArr[i]);
    if (sum == n)
        return "Yes...";
    return "No...";
}
int main()
{
    cout << armstrongNumber(13) << endl;
    return 0;
}