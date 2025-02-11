#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter How many number do you want to store:";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nYour Array numbers:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}