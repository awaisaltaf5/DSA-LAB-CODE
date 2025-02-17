#include <iostream>
using namespace std;
int main()
{
    int length = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int flag = 0;
    int element;
    cout << "Enter Element to search:";
    cin >> element;
    int i = 0;
    while (i < length)
    {
        if (arr[i] == element)
        {
            flag++;
            break;
        }
        else
        {
            i++;
        }
    }
    if (flag > 0)
    {
        cout << "Element found at " << i << " Index!";
    }
    else
    {
        cout << "Element Not Found";
    }
    return 0;
}