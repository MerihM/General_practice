// complete the function find_median() which takes the array
// as input parameter and returns the floor value of the median.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

float find_median(int arr[], int size)
{

    if (size % 2 == 1)
        return float(arr[(size / 2)]);
    else
        return (arr[size / 2] + arr[(size / 2) - 1]) / 2 * 1.0;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 10, 11, 13, 15};
    int al = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + al);
    cout << find_median(arr, al) << endl;
    return 0;
}