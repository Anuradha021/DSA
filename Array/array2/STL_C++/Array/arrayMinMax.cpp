#include<iostream>
using namespace std;
int getMax(int array[],int size){

int maxi = INT_MIN;
for(int i = 0;i<size;i++){
    maxi = max(maxi,array[i]);
   // if(array[i]>max){
      //  max = array[i];
    //}
}
return maxi;
}
int getMin(int array[],int size){
int min = INT_MAX;
for(int i = 0;i<size;i++){
    if(array[i]<min){
        min= array[i];
    }
}
return min;
}
int main(){
int size ;
cout<<"enter the size of array "<<endl;
cin>>size;
int Num[size];
for(int i =0;i<size;i++){
    cin>>Num[i];
}

cout<<"maximum element is "<<getMax(Num,size)<<endl;

cout<<"minimum element of the array is "<<getMin(Num,size)<<endl;
return 0;

}