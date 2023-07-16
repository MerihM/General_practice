#include <iostream>
#include <string>

using namespace std;

int sumElement(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int al = sizeof(arr) / sizeof(arr[0]);
    cout << sumElement(arr, al) << endl;
    return 0;
}