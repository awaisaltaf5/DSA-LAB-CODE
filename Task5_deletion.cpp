#include <iostream>
using namespace std;
int main()
{
    int length = 5;
    int arr[length] = {1, 2, 3, 4, 5};
    int position = 4;
    for (int i = position; i < length; i++)
    {
        arr[i - 1] = arr[i];
    }
    length--;
    cout << "Array with deletion:\n";
    for (int i = 0; i <= length - 1; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}