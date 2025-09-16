#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    vector<int> used(n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        used[a[i]]=1;
        cnt+=(a[i]==0);
    }
    if(cnt==1){
        for(int i=1;i<=n;i++){
            if(a[i]==0 && used[i]==0){
                a[i]=i;
            }
        }
    }
    int l=1,r=n;
    while(l<=n && a[l]==l) l++;
    while(r>=1 && a[r]==r) r--;
    if(r<=l){
        cout<<0<<'\n';
        return;
    }
    cout<<r-l+1<<'\n';
}




int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}