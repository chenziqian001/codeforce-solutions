#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long sum=0;
    for(int i=1;i<n;i++){
        auto low=lower_bound(a.begin(),a.end(),i);
        auto high=lower_bound(a.begin(),a.end(),n-i);
        long long tl=m-(low-a.begin());
        long long hl=m-(high-a.begin());
        sum=sum+tl*hl-min(tl,hl);
    }
    cout<<sum<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}