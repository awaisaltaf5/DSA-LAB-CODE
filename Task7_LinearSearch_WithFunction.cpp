#include <iostream>
using namespace std;
int linearSearch(int arr[], int length, int element)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int length = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int element;
    cout << "Enter Element to search:";
    cin >> element;
    int result = linearSearch(arr, length, element);
    if (result != -1)
    {
        cout << "Element is found at " << result << " Index";
    }
    else
    {
        cout << "Element is not found!";
    }
    return 0;
}
