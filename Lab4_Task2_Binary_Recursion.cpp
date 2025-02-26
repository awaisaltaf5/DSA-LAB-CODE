#include<iostream>
using namespace std;

int binarySearch(int element, int arr[], int beg, int end){
    if (beg > end) {
        return -1;
    } 
    else {
        int mid = (beg+end)/2; 
        if (arr[mid] == element) {
            return mid;
        } 
        else if (arr[mid] < element) {
            return binarySearch(element, arr, mid + 1, end); 
        } 
        else {
            return binarySearch(element, arr, beg, mid - 1); 
        }
    }
}

int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int beg = 0;
    int end = n - 1;
    int element = 4;
    
    cout << "Element found at index: " << binarySearch(element, arr, beg, end);
    return 0;
}

