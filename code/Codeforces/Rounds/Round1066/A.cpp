#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    int res=0;
    for(int i=0;i<=n;i++){
        if(cnt[i]==0) continue;

        if(cnt[i]!=i){
            if(cnt[i]<i){
                res+=cnt[i];
            }
            else res+=-i+cnt[i];
        }
    }

    cout<<res<<'\n';


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}