#include<iostream>
using namespace std;
bool linearSearch(int arr[],int size,int key ){
    
for(int i = 0;i<size;i++){
if(arr[i] == key ){
return 1;
}

}
return 0;
}
int main(){
    int key;

int size;
cout<<"enter the size of Array "<<endl;
cin>>size;
int Num[size];

for(int i = 0;i<size;i++){
    cin>>Num[i];
}
cout<<"ener the element whichh you want to search "<<endl;
cin>>key;
bool found = linearSearch(Num,size,key);
if(found){
    cout<<"element is found"<<endl;
}
else{
    cout<<"element is not found"<<endl;
}

}