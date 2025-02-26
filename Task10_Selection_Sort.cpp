#include<iostream>
using namespace std;

int main() {
    int length = 5; 
    int arr[5] = {2, 3, 1, 4, 5};
    for (int i = 0; i < length - 1; i++) {
    
        for (int j = i + 1; j < length; j++) {
            
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
