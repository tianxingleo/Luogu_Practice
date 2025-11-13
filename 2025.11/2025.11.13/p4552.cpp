#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>diff(n+1,0);
    diff[0]=arr[0];
    for(int i=1;i<n;i++){
        diff[i]=arr[i]-arr[i-1];
    }
    int sum=0;
    for(int i=1;i<n;i++){
        if(diff[i]>0){
            sum+=diff[i];
        }
    }
    cout<<sum<<endl<<*max_element(arr.begin(),arr.end())-*min_element(arr.begin(),arr.end())+1;
}