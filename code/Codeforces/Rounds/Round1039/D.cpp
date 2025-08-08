#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long ans=1,cur=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]) cur++;
        else cur+=(i+1);
        ans+=cur;
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}