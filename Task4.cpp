#include <iostream>
using namespace std;
int main()
{
    int length = 5;
    int arr[6] = {1, 2, 3, 4, 5};
    int position = 3;

    int element = 7;
    cout << "Array element with insertion of 1 element at specific position:\n";
    for (int i = length; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    for (int i = 0; i <= length; i++)
    {
        cout << arr[i];
    }

    return 0;
}