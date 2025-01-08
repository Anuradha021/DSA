#include<iostream>
using namespace std;

int firstOcc(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    
    while (start <= end) {
        if (arr[mid] == key) {
            ans = mid;     
            end = mid - 1; 
        }
        else if (key > arr[mid]) {
            start = mid + 1; 
        }
        else {
            end = mid - 1;   
        }
        mid = start + (end - start) / 2; 
    }
    return ans;
}

int lastOcc(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    
    while (start <= end) {
        if (arr[mid] == key) {
            ans = mid;     
            start = mid + 1; 
        }
        else if (key > arr[mid]) {
            start = mid + 1; 
        }
        else {
            end = mid - 1;   
        }
        mid = start + (end - start) / 2; 
    }
    return ans;
}

int main() {
    int even[6] = {2, 3, 4, 5, 4, 8};
   
    cout << "First occurrence of 4 is: " << firstOcc(even, 6, 4) << endl; 
    cout << "Last occurrence of 4 is: " << lastOcc(even, 6, 4) << endl; 

    return 0;
}
