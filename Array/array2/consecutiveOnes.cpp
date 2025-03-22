#include<iostream>
#include<vector>
using namespace std;
int consecutiveOnes(vector<int> &nums,int n){
    int maxi =0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else{
            cnt =0;
        }
    }
    return maxi;
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
    cout << "Consecutive number of ones is: "<<consecutiveOnes(a,n);
    return 0;
}