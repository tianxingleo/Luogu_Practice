#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<long long> diff(n);
    diff[0] = a[0];
    for(int i=1;i<n;i++) diff[i] = a[i] - a[i-1];

    long long pos = 0, neg = 0;
    for(int i=1;i<n;i++){
        if(diff[i] > 0) pos += diff[i];
        else neg -= diff[i];
    }

    cout << max(pos, neg) << "\n" << abs(pos - neg) + 1 << "\n";
    return 0;
}
