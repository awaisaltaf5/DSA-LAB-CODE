#include <iostream>
using namespace std;
int main()
{
    int length = 6;
    int arr[6] = {1, 2, 3, 4, 5};
    cout << "Array without insertion\n";
    for (int i = 0; i < length - 1; i++)
    {
        cout << arr[i] << endl;
    }

    int element = 7;
    arr[length - 1] = element;
    cout << "Array element with insertion of 1 element:\n";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}