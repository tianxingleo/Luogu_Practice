#include <bits/stdc++.h>
using namespace std;

void free(vector<vector<int>>&arr,int x_1,int y_1,int x_2,int y_2){
    for(int i=x_1;i<=(x_1+x_2)/2;i++){
        for(int j=y_1;j<=(y_1+y_2)/2;j++){
            arr[i][j]=0;
        }
    }
    if(x_2-x_1>=2){
        free(arr,(x_1+x_2)/2+1,y_1,x_2,(y_1+y_2)/2);
        free(arr,x_1,(y_1+y_2)/2+1,(x_1+x_2)/2,y_2);
        free(arr,(x_1+x_2)/2+1,(y_1+y_2)/2+1,x_2,y_2);
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(pow(2,n),vector<int>(pow(2,n),1));
    free(arr,0,0,pow(2,n)-1,pow(2,n)-1);
    for(int i=0;i<=pow(2,n)-1;i++){
        for(int j=0;j<=pow(2,n)-1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;

    }
    return 0;
}