#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<int> c(n+1),l(n+1),ans(n+1,-1),mf(n+1);
    vector<bool> vis(n+1);
    int tot=0;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            tot++;
            int u=i,len=0;
            while(!vis[u]){
                vis[u]=1;
                c[u]=tot;
                len++;
                u=a[u];
            }
            l[tot]=len;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=-1){
            if(ans[i]==-1){
                int u=c[i],v=c[b[i]];
                if(l[u]!=l[v] || (mf[v] && mf[v]!=u)){
                    cout<<"NO"<<'\n';
                    return;
                }
                mf[v]=u;
                int x=i,y=b[i];
                for(int j=0;j<l[u];j++){
                    if(ans[x]!=-1 && ans[x]!=y){
                        cout<<"NO"<<'\n';
                        return;
                    }
                    ans[x]=y;
                    x=a[x];  
                    y=a[y];
                }
            }else if(ans[i]!=b[i]){
                cout<<"NO"<<'\n';
                return;
            }
        }
    }

    vector<set<int>> s(n+1);
    for(int i=1;i<=n;i++){
        if(!mf[c[i]]) s[l[c[i]]].insert(i);
    }

    for(int i=1;i<=n;i++){
        if(ans[i]==-1){
            int len=l[c[i]];
            
            if(s[len].empty()){
                cout<<"NO"<<'\n';
                return;
            }
            int v=*s[len].begin();
            int x=i,y=v;
            for(int j=0;j<len;j++){
                ans[x]=y;
                s[len].erase(y);
                x=a[x];
                y=a[y];
            }
        }
    }

    cout<<"YES"<<'\n';
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}