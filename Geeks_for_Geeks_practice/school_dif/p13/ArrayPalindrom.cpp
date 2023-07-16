// complete the function PalinArray. Which will return 1 if all the elements
// of the Array are palindrome otherwise it will return 0.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int PalinArray(int arr[], int size)
{
    vector<int> tempArr;
    for (int i = 0; i < size; i++)
    {
        string s = "", sa = "";
        int temp = arr[i];
        sa = to_string(arr[i]);
        while (temp > 0)
        {
            tempArr.push_back(temp % 10);
            s.append(to_string(temp % 10));
            temp /= 10;
        }
        if (sa != s)
            return 0;
    }
    return 1;
}
int main()
{
    int arr[] = {121, 222, 333, 20};
    int al = sizeof(arr) / sizeof(arr[0]);
    cout << PalinArray(arr, al) << endl;
    return 0;
}