//Remove duplicates from sorted array 
//I/P:= {1,1,2,2,2,3,3}
//O/P:= {1,2,3}
#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>&arr ,int n){
int i =0;
for(int j=1;j<n;j++){
if(arr[j]!=arr[i]){
    arr[i+1] = arr[j];
    i++;
}
}
return i+1;//bcz at the end it is showing n-1 index thats why we are returning i+1
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = removeDuplicates(a,n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < result; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
