#include<iostream>
using namespace std;


void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
}
void sortOne(int num[],int size){
    int left = 0;
    
    int right = size-1;
    while(left < right){
        while(num[left]==0 && left < right ){
           left++;
        }
        while(num[right]==1 && left <right ){
            right--;
        }
        //arr[left]==1 and arr[right]==0
        //swap them 
        if(left<right){
        swap(num[left],num[right]);
        left++;
        right--;
        }
    }
}
int main(){
    int arr[8] = {0,1,1,0,1,1,0,0};
    sortOne(arr,8);
    printArray(arr,8);
}

