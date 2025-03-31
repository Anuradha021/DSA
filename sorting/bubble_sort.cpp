//push the maximum to the last by adjacent swaps

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void bubble_sort(int &arr[],int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
        //here why j is going {i-1} because at the last index no try to next elemnt which is not present thats why 
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
        }
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        bubble_sort(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
    
}