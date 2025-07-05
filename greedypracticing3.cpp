#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void solve(){
    int n,x;
    cin>>n>>x;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long sum=0;
    long long maxi=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        maxi=max(maxi,a[i]);
    }

    cout<<max(maxi,(sum+x-1)/x)<<'\n';
    return;

}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}