#include <iostream>
using namespace std;

int seriesSum(int n)
{
    return ((n * (1 + n)) / 2);
}
int main()
{
    cout << seriesSum(100) << endl;
    return 0;
}