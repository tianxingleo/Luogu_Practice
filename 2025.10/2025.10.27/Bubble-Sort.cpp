#include <iostream>
#include <vector>

using namespace std;
int main(){
    cout<<"输入数组长度";
    int n;
    cin>>n;

    vector<int>shuzu(n);
    cout<<"输入数组";
    for(int i=0;i<=n-1;i++){
        cin>>shuzu[i];
    }
    int sum=0;
    int a=0;
    int b=0;
    for(;;){
        sum=0;
        for(int i=0;i+1<=n-1-b;i++){
            
            if(shuzu[i]>shuzu[i+1]){
                a=shuzu[i];
                shuzu[i]=shuzu[i+1];
                shuzu[i+1]=a;
                sum+=1;
            }

        }

        if(sum==0){
            break;
        }
        b+=1;
    }



    for(int i=0;i<=n-1;i++){
        printf("%d ",shuzu[i]);
    }
}