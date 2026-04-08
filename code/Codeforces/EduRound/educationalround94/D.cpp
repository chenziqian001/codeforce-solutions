#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    int ans=0;
    vector<int> c1(n),c2(n);
    
    for(int i=0;i<n;i++){
        fill(c1.begin(),c1.end(),0);
        fill(c2.begin(),c2.end(),0);
        for(int l=i+1;l<n;l++){
            c2[a[l]]++;
        }
        int res=0;

        for(int k=i+1;k<n;k++){
            int x=a[k];
            res-=c1[x];
            c2[x]--;

            if(a[i]==a[k]){
                ans+=res;
            }

            res+=c2[x];
            c1[x]++;
        }

    }

    cout<<ans<<'\n';





}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}