#include <iostream>
using namespace std;
int BinarySearch(int arr[], int length, int start, int end, int element)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int length = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = length - 1;
    int element;
    cout << "Enter the Element:";
    cin >> element;
    int result = BinarySearch(arr, length, start, end, element);
    if (result != -1)
    {
        cout << "Element is found at " << result << " Index";
    }
    else
    {
        cout << "Element is not found!";
    }
}