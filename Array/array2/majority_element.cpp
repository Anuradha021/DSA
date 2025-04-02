#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int n) {
    int candidate = -1, count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    return (count > n / 2) ? candidate : -1;
}

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int majorityElement = findMajorityElement(arr, n);
    if (majorityElement != -1)
        cout << "Majority Element: " << majorityElement << endl;
    else
        cout << "No Majority Element Found" << endl;

    return 0;
}
