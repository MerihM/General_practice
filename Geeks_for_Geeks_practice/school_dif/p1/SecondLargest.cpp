#include <iostream>
#include <string>

using namespace std;

int print2largest(int Arr[], int n)
{
    int largest, second;
    if (n <= 1 || (n == 2 && Arr[0] == Arr[1]))
        return -1;
    if (Arr[0] != Arr[1])
    {
        largest = max(Arr[0], Arr[1]);
        second = min(Arr[0], Arr[1]);
    }
    else
    {
        largest = Arr[0];
        second = 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (Arr[i] > largest)
        {
            second = largest;
            largest = Arr[i];
        }
        else if (Arr[i] < largest && Arr[i] > second)
            second = Arr[i];
    }
    return second;
}
int main()
{
    int arr[] = {5, 10, 10, 10};
    int al = sizeof(arr) / sizeof(arr[0]); // length calculation
    // cout << "The length of the array is: " << al << endl;
    cout << print2largest(arr, al) << endl;
    return 0;
}