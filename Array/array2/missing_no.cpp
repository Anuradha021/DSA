#include<iostream>
#include<vector>
using namespace std;
int missing_no(vector<int> a,int n){
    int sum = 0;
    sum = sum + n*(n+1)/2;
    int sum2 = 0;
    for(int i =0;i<n-1;i++){
    sum2 = sum2 + a[i];
    }
    return sum - sum2;
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n-1);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout<<"missing no is :"<<missing_no(a,n);
    return 0;
}