/*
takes an element & place it in its correct order 
*/
//push the maximum to the last by adjacent swaps
//worst and avg case complexity = o(n^2) and best case o(n )
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0&&arr[j-1]>arr[j]){
           int temp = arr[j-1];
           arr[j-1] = arr[j];
           arr[j] = temp;
           j--;
        }
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        insertion_sort(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
    
}