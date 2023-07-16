// Complete the function isBinary() which takes an string str as input
//  parameter and returns 1 if str is binary and returns 0 otherwise.

#include <iostream>
#include <string>
using namespace std;

int isBinary(string str)
{
    bool check = true;

    if (!(str.find("1") != string::npos) || !(str.find("0") != string::npos))
        check = false;
    if (!check)
        return 0;
    return 1;
}
int main()
{
    cout << isBinary("121") << endl;
    return 0;
}