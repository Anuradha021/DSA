#include<iostream>
using namespace std;


//-----------------------------UNIQUE ELEMENT FIND OPTIMIZED  TECHNIQUE(leetcode q)-----------------------------//
//XOR mein same element ka xor 0 hota hai or 0 ke sath kisi element ka xor usi number k deta hai 
//ex ---> {1,2,1,2,4} in this example 1^1 cut each other 2^2 cut each other and ans will be 4 ...


int  uniqueElment(int arr[],int n){
    int ans;
    for(int i =0;i<n;i++){
          ans = ans^arr[i];
    }
    return ans  ;
}



void printArray(int arr[],int n){
for(int i=0; i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int main(){
    int arr[5]= {1,2,2,3,3};
    
 cout<<"unique element is "<< uniqueElment(arr,5);
    //printArray(arr,5);
}