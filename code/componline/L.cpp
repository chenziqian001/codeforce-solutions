#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int ch[N][26],sz[N],dep[N],tot;
int ans[N];

void solve(){
    int n;
    cin>>n;
    int sum=0;tot=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        sum+=i;
        int u=0;
        for(int j=0;j<s.size();j++){
            int c=s[j]-'a';
            if(!ch[u][c]){
                ch[u][c]=++tot;
                dep[tot]=dep[u]+1;
            }
            u=ch[u][c];
            sz[u]++;
            int k=sz[u];
            if(dep[u]>ans[k]){
                sum-=(ans[k]^k);
                ans[k]=dep[u];
                sum+=(ans[k]^k);
            }
        }
        cout<<sum<<'\n';
    }    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}

