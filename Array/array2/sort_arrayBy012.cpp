#include<iostream>
uisng namespace std;
#include<vector>
void sortArray(vector<int>&a,int n){
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
           mid++;
        }
        else{
         swap(a[mid],a[high]);
         high--;
        }
    }
}
void printArray(vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
int n;
cin>>n;
vector<int>a(n);
cout << "Enter the elements (0, 1, 2 only): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sortArray(a, n);
    cout << "Sorted array: ";
    printArray(a, n);

    return 0;

}