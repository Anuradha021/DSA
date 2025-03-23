#include<iostream>
#include <map>
using namespace std;
#include<vector>
int majorityElement(vector<int>&arr){
    map<int,int>mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    for(auto it :mpp){
        if(it.second>(arr.size()/2)){
            return it.first;
        }
    }
    return -1;
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = majorityElement(arr);
    if (res != -1) {
        cout << "Majority element is: " << res << endl;
    } else {
        cout << "No majority element found." << endl;
    }
    return 0;
}