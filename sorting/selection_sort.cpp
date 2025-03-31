#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//time complexity in all case is almost O(n^2){
// loop will run like n .n-1,n-2 ...so on it is like n natural number sum that is n(n+1)/2 which is n^2}
void selection_sort(int &arr[],int n){
    for(int i=0;i<n-2;i++){
        int mini = i;
        for(int j=i;j<n-1;j++){
          if(arr[j]<arr[mini]){
            mini = j;
          }
          
        }
        swap(arr[mini],arr[i]);
         /*
         swap function ->
         int temp = arr[mini]
         arr[mini] = arr[i]
         arr[i] = temp
         */
    }
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        selection_sort(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
    
}
