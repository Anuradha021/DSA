#include<iostream>
using namespace std;
void swapAlternative(int arr[],int n){
for(int i =0; i<n; i= i+2){
    if(i+1<n){
 //swap(arr[i],arr[i+1]);
 int temp = arr[i];
 arr[i]= arr[i+1];
 arr[i+1]= temp;
    }
   
}
}
void printArray(int arr[],int n){
for(int i=0; i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

int main(){
int arr[6] = {1,2,3,4,5,6};
int odd[5]= {1,2,3,4,5};

swapAlternative(arr,6);
swapAlternative(odd,5);
printArray(arr,6);
printArray(odd,5);
}