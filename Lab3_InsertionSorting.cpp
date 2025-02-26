#include <iostream>
using namespace std;

int insertion_Sort(int arr[], int length)
{

    for (int i = 1; i < length; i++)
    {

        int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int length = 5;
    int arr[5] = {2, 3, 4, 1, 5};

    cout << "Unsorted Array:\n";

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    insertion_Sort(arr, length);

    cout << "\nSorted Array:\n";

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
