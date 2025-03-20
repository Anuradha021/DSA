//left rotate by one place 
#include<iostream>
#include<vector>
using namespace std;
vector<int> rotateArray(vector<int>a,int n){
    int temp = a[0];
    for(int i =1;i<n;i++){
        a[i-1] = a[i];
    }
    a[n-1] = temp;
    return a;
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
    vector<int> result = rotateArray(a, n);
    
 cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}