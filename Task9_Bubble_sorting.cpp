#include <iostream>
using namespace std;
int main()
{
    int length = 5;
    int arr[5] = {1, 3, 5, 4, 2};
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        cout << arr[i];
    }
    return 0;
}