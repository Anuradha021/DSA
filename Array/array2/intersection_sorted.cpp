#include<iostream>
#include<vector>
using namespace std;
vector<int> intersection_Sorted(vector<int> &a,int n,vector<int> &b,int m){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<m){
     if(a[i]<b[j]){
        i++;
     }
     else if(b[j]<a[i]){
        j++;
     }
     else{
        ans.push_back(a[i]);
        i++;
        j++;
     }
    }
    return ans;


}

int main(){

    int n;
    cout << "Enter the number of elements in 1 array : ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cout << "Enter the number of elements in 2 array : ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter the elements: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<int> result = intersection_Sorted(a,n, b,m);
    int n3 = result.size();
    for (int i = 0; i < n3; i++) {
        cout << result[i] << " ";
    }
    return 0;
}