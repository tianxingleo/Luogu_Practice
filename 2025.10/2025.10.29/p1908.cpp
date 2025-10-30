// #include <bits/stdc++.h>
// using nam std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int>shulie(n+1,0);
//     for(int i=0;i<=n-1;i++){
//         cin>>shulie[i];
//     }espace
//     shulie[n]=0;
//     int sum=0;
//     for(int i=0;i<=n-2;i++){
//         vector<int>shulie_1=shulie;
//         sort(shulie_1.begin()+i+1,shulie_1.begin()+n);
//         for (int j=i+1;shulie_1[j]<shulie_1[i]&&j<=n-1;j++){
//             sum++;
//         }
//     }
//     cout<<sum;
//     return 0;
// }


// #include <stdio.h>
// #include <vector>

// int main(){

    
//     int n;
//     scanf("%d",&n);
//     std::vector<int>shulie(n,0);
//     for(int i=0;i<=n-1;i++){
//         scanf("%d",&shulie[i]);
//     }
//     int sum=0;
//     for(int i=0;i<=n-2;i++){
//         for (int j=i+1;j<=n-1;j++){
//             if(shulie[i]>shulie[j]){
//                 sum++;
//             }
//         }
//     }
//     printf("%d",sum);
// }


#include <bits/stdc++.h>
using namespace std;

long long int sum=0;

void merge(vector<int>&arr,int min,int mid,int max){
    vector<int>temp;
    int i=min,j=mid+1;
    int second=0;
    while(i<=mid&&j<=max){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
            sum+=second;
        }else{
            temp.push_back(arr[j]);
            j++;
            second++;
        }
    }
    while(j<=max){
        temp.push_back(arr[j]);
        j++;
        second++;
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
        sum+=second;
    }
    for(int i=min;i<=max;i++){
        arr[i]=temp[i-min];
    }
}

void sort(vector<int>&arr,int min,int max){
    if(min<max){
        int mid=(min+max)/2;
        sort(arr,min,mid);
        sort(arr,mid+1,max);
        merge(arr,min,mid,max);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    std::vector<int>shulie(n,0);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&shulie[i]);
    }
    sort(shulie,0,n-1);
    cout<<sum;
    return 0;
}