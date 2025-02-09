#include<iostream>
#include<array>
using namespace std;
int main(){
    int normal_array[3] = {1,2,3};
    //STL array
    array<int,4> a={1,2,3,4};
    int size = a.size();
    for(int i =0;i<size;i++){
        cout<<a[i]<<endl;
    }
    cout<<"Elemnt at index 2 is ::"<<a.at(2)<<endl;
    cout<<"front element"<<a.front()<<endl;
    cout<<"back element"<<a.back()<<endl;

}
