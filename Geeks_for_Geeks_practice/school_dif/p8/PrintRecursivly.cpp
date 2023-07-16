// Complete the function printNos()
// that takes N as parameter and prints number from 1 to N recursively.

#include <iostream>
#include <string>
using namespace std;

int ctr = 1;
void printNos(int N)
{
    if (ctr > N)
        return;
    cout << ctr++ << " ";
    printNos(N);
}
int main()
{
    printNos(10);
    cout << endl;
    return 0;
}