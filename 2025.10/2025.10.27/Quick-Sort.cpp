//快速排序的实现

#include <iostream>
#include <vector>
using namespace std;


int fenqu(vector<int> &arr,int low,int high){
    int jizhun=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if (arr[j]<jizhun){
            swap(arr[i],arr[j]);
            i++;
        }

    }
    swap(arr[high],arr[i]);
    return i;
}


void paixu(vector<int>&arr,int low,int high){
    if(low<high){
        int i=fenqu(arr,low,high);
        paixu(arr,low,i-1);
        paixu(arr,i+1,high);
    }
}

int main(){
    int n;
    cout<<"请输入数组的位数：";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    paixu(arr,0,n-1);

    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}



/*
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {7, 2, 5, 3, 6, 1};
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
}
*/











/*
#include <iostream>
#include <vector>
using namespace std;

//int paixu()

int main(){

    cout<<"输入数组长度";
    int n;
    cin>>n;

    vector<int>shuzu(n);
    cout<<"输入数组";
    for(int i=0;i<=n-1;i++){
        cin>>shuzu[i];
    }

    vector<int>shuzu_1;
    vector<int>shuzu_2;
    int a=shuzu[0];//标定数字
    for(int i=0;i<=n-1;i++){
        if(shuzu[i]<=a){
            shuzu_1.push_back(a);
        }else{
            shuzu_2.push_back(a);
        }
    }


}
*/


