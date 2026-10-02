#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int s=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s+=x;
    }
    int b=n*(n-1)/2;
    int d=s-b;
    int q=d/n;
    int r=d%n;
    for(int i=0;i<n;i++){
        cout<<i+q+(i<r?1:0)<<" ";
    }
    //system("pause");
    return 0;
}