using namespace std;
#include<iostream>

long long int sqrtInteger(int n){
    
    if (n == 0) return 0; 
        if (n == 1) return 1;
    int s = 0;
    int e = n;
    long long int  mid = s+ (e-s)/2;
    int ans =-1;
    while(s <= e){
        long long int square = mid * mid ;
        if(square == n ){
            return mid ;
        }
        if( square < n ){
           ans = mid ;
           s = mid + 1;
        }
        else{
  e = mid -1 ;
        }
        mid = s + (e -s)/2;
        
    }
    return ans;
}

double morePrecision(int n,int precision,int tempSol){
    double factor = 1;
    double ans = tempSol;
    for(int i =0;i<precision;i++){
        factor = factor/10;
        for(double j = ans; j*j<n;j = j+factor){
            ans = j;
        }
    }
    return ans ;
}

int main(){
    int n;
    cout<<"ENter a number"<<endl;

    cin>>n;
    int tempSol = sqrtInteger(n);
    cout<<"Answer is "<<morePrecision(n,3,tempSol)<<endl;
    return 0;
}