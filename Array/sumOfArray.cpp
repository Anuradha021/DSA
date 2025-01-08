#include<iostream>
using namespace std;
int sumOfArray(int arr[],int size){
    int sum = 0;
    for(int i =0;i<size;i++){
        sum = sum + arr[i];
    }
    return sum ;
}

int main(){
int size;
cout<<"enter the size of Array "<<endl;
cin>>size;
int Num[size];
for(int i = 0;i<size;i++){
    cin>>Num[i];
}
cout<<"sum of array element is "<<sumOfArray(Num,size)<<endl;
}