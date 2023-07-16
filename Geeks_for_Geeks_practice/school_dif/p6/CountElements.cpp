#include <iostream>
using namespace std;

int countOfElements(int arr[], int n, int y)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= y)
            num++;
    }
    return num;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 5, 7, 9};
    int al = sizeof(arr) / sizeof(arr[0]);
    int check = 2;

    cout << countOfElements(arr, al, check) << endl;
    return 0;
}