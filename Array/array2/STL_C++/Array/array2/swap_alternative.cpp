#include<iostream>
using namespace std;

// int main(){
// int n;
//     cout<<"enter the no of value you want to insert ";
//     cin>>n;
//     int arr[n];
//     for(int i =0;i<n;i++){
//         cin>>arr[i];
//     }
//     //cout<<"without swap alternative";
//     for(int i =0;i<n;i= i+2){
//         if(i+1<n){
//         int temp = arr[i];
//         arr[i]= arr[i+1];
//         arr[i+1] = temp;
//     }
//     }
//     for(int i =0;i<n;i++){
//         cout<<arr[i];
//     }

// }
void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";

    }cout<< endl;
}
void swapAlternative(int arr[],int n){
for(int i =0;i<n;i= i+2){
        if(i+1<n){
        int temp = arr[i];
        arr[i]= arr[i+1];
        arr[i+1] = temp;
    }
    }
}
int main(){
    int even[8] = {2,5,7,8,1,0,4,6};
    int odd[7] = {1,2,3,4,5,6,7};
    swapAlternative(even,8);
    printArray(even,8);
    cout<<endl;
    swapAlternative(odd,7);
    printArray(odd,7);
    

}
