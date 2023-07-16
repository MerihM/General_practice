// complete the function printPat() which takes one argument 'N' denoting the length of the pattern.

#include <iostream>
using namespace std;

void printXTimes(int num, int times)
{
    for (int i = 0; i < times; i++)
        cout << num;
}
void printPat(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N; j > 0; j--)
            printXTimes(j, (N - i));
        cout << endl;
    }
}
int main()
{
    printPat(3);
    return 0;
}