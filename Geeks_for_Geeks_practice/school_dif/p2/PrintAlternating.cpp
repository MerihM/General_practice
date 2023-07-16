#include <iostream>
#include <string>

using namespace std;

void print(int arr[], int n)
{
    string Alternating = "";
    for (int i = 0; i < n; i += 2)
        Alternating.append(to_string(arr[i])).append(", ");
    Alternating.resize(Alternating.size() - 2);
    cout << Alternating << endl;
}
int main()
{
    int arr[] = {5, 10, 10, 10, 11};
    int al = sizeof(arr) / sizeof(arr[0]); // length calculation
    print(arr, al);
    return 0;
}