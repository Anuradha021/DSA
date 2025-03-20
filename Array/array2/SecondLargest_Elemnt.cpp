#include<iostream>
#include <climits>//for INT_MAX
using namespace std;
int secondLargest(vector<int>&a,int n){
    if (n < 2) return -1; 
    int largest = a[0];  //{1,2,4,7,7,5}
    int sLargest = -1;
    for(int i=1;i<n;i++){
        if(a[i]>largest ){
            sLargest=largest;
            largest = a[i];
        }
        else if(a[i]<largest && a[i]>sLargest){
            sLargest = a[i];
        }
    }
    return sLargest;
}
int secondSmallest(vector<int>&a,int n){
    if (n < 2) return -1; 
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i= 1;i<n;i++){
     if(a[i]<smallest){
        ssmallest = smallest;
        smallest = a[i];
     }
     else if(a[i]!= smallest &&a[i]<smallest){
        ssmallest = a[i];
     }
    }
    return ssmallest;
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
int sLargest = secondLargest(a,n);
int ssmallest = secondSmallest(a,n);
cout << "Second Largest: " << sLargest << endl;
cout << "Second Smallest: " << sSmallest << endl;
return 0;
}