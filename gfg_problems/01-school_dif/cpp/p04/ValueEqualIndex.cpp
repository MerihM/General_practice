#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> tempArr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
            tempArr.push_back(arr[i]);
    }
    return tempArr;
}
int main()
{
    int arr[] = {2, 1, 4, 5, 1};
    int al = sizeof(arr) / sizeof(arr[0]);
    string s = "";
    vector<int> newArr = valueEqualToIndex(arr, al);
    if (newArr.size() > 0)
    {
        for (int i = 0; i < newArr.size(); i++)
            s.append(to_string(newArr[i])).append(", ");
        s.resize(s.size() - 2);
    }
    else
        s.append("0");

    cout << s << endl;
}