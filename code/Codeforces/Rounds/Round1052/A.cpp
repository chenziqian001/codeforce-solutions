#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> cnt(n+1);
    for(int i=0;i<n;i++) cnt[a[i]]++;
    int res=0;
    for(int len=1;len<=n;len++){
        int cur=0;
        for(int i=1;i<=n;i++){
            if(cnt[i]==0) continue;
            if(cnt[i]>=len){
                cur+=len;
            }
        }
        res=max(res,cur);
    }

    cout<<res<<'\n';



}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}