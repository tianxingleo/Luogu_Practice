#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;//数列长度
    
    cin>>n;
    vector<int> each(n+1,0);
    vector<int> sum_each(n+1,0);//每一次求和
    int sum_temp=0;
    for(int i=1;i<=n;i++){
        cin>>each[i];
        sum_temp+=each[i];
        sum_each[i]=sum_temp;
    }
    int m;
    cin>>m;
    vector<vector<int>>range_list(m+1,vector<int>(2,0));
    for(int i=1;i<=m;i++){
        cin>>range_list[i][0]>>range_list[i][1];
    }

    vector<int>sum(m+1,0);
    for(int i=1;i<=m;i++){
        sum[i]=sum_each[range_list[i][1]]-sum_each[range_list[i][0]-1];
        cout<<sum[i]<<endl;
    }


    return 0;
}