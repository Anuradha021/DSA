#include<iostream>
using namespace std;
// #include <bits/stdc++.h>
#include<vector>
vector<int>rotateArray(vector<int> &arr ,int n){
    int temp = arr[0];
    for(int i =1;i<n;i++){
        arr[i-1] = arr[i];

    }
    arr[n-1] = temp;

    return arr;
}
int main(){

    vector<int> arr = {1,2,3,4,5};
    rotateArray(arr,5);
    for(int num :arr){
        cout <<num <<" ";
    }
    return 0;
}
