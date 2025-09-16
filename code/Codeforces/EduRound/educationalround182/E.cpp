#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> lef={0};
    vector<int> rig={0};
    for(int i=0;i<n;i++){
        if(a[i]>=lef.back()){
            lef.push_back(a[i]);
        }
    } 
    for(int i=n-1;i>=0;i--){
        if(a[i]>=rig.back()){
            rig.push_back(a[i]);
        }
    }
    int lsiz=lef.size()-1;
    int rsiz=rig.size()-1;
    int h=*max_element(a.begin()+1,a.end());
    vector<vector<int>> pre(n+1,vector<int>(lsiz+1,0));
    vector<vector<int>> suf(n+2,vector<int>(rsiz+1,0));

    pre[0][0]=1;
    suf[n+1][0]=1;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1];
        for(int j=0;j<lsiz;j++){
            if(a[i]<=lef[i]){
                pre[i][j]=(pre[i][j]+pre[i-1][j])%mod;
            }
            else if(a[i]==lef[i+1]){
                pre[i][j+1]=(pre[i][j+1]+pre[i-1][j])%mod;
            }
        }
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1];
        for(int j=0;j<=rsiz;j++){
            if(a[i]<=rig[i]){
                suf[i][j]=(suf[i][j]+suf[i+1][j])%mod;
            }
            else if(j<rsiz && a[i]==rig[i+1]){
                suf[i][j+1]=(suf[i][j+1]+suf[i+1][j])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==h){
            ans=(ans+(pre[i-1][lsiz]+pre[i-1][lsiz-1])%mod*((suf[i+1][rsiz]+suf[i+1][rsiz-1])%mod)%mod);
        }
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