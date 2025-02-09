#include <bits/stdc++.h>
#include<iostream>
using namespace std;
class solution {
public:
bool uniqueOccourances(vector<int>arr){
vector<int> ans;
int size = arr.size();
sort(arr.begin(),arr.end());
int i =0;
while(i<size){
    int count =1;
    for(int j = 0;j<size;j++){
        if(arr[i]==arr[j]){
            count ++;
        }
        else{
            break;
        }
    }
    ans.push_back(count);
    i = i+count;

}
int size = ans.size();
sort(ans.begin(),ans.end());
for(int i =0;i<size;i++){
    if(ans[i]==ans[i+1]){
        return false;
    }
}
return true;
}
};
