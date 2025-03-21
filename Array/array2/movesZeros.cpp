
#include<iostream>
#include<vector>
using namespace std;
vector<int> movesZeros(vector<int> a ,int n){
    int j =-1;
    //step 1
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j =i;
            break;
        }
    }
    //no zero numbers
    if(j==-1) return a;
    //step 2
    for(int i =j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
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
  vector<int> result = movesZeros(a, n);
cout << "Array after moving zeros to the end: ";
for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
}
cout << endl;
   
    cout << endl;
    
    return 0;
}