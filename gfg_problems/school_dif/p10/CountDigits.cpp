// complete the function evenlyDivides() which takes an integer N as input parameters
//  and returns an integer, total number factor of digits N which divides N evenly.
#include <iostream>
#include <vector>
using namespace std;

int evenlyDevides(int N)
{
    int ctr = 0, tempN = N;
    vector<int> tempArr;
    while (tempN > 0)
    {
        if (N % (tempN % 10) == 0)
            ctr++;
        tempArr.push_back(tempN % 10);
        tempN /= 10;
    }
    return ctr;
}
int main()
{
    cout << evenlyDevides(23) << endl;
    return 0;
}