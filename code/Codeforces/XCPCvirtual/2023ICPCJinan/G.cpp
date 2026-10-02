#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

/*
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int k;
    if(m%2==0) k=m/2;
    else k=(m+1)/2;
    vector<int> st(k);
    int res=1;
    for(int i=0;i<n;i++){
        bool ok=true;
        for(int j=0;j<k;j++){
            int val;
            if(a[i][j]=='0' && a[i][m-j-1]=='0') val=0;
            else if(a[i][j]=='1' && a[i][m-j-1]=='1') val=2;
            else val=1; 
            if(st[j]==2){
                if(val>=1){
                    cout<<0<<'\n';
                    return;
                }
            }
            else if(st[j]==0){
                st[j]=val;
            }
            else{
                if(val==2){
                    cout<<0<<'\n';
                    return;
                }
                else{
                    if(val==1){
                        ok=false;
                        st[j]=2;
                    }
                }
            }
        }
        if(ok) res=res*2%mod;
    }
    cout<<res<<'\n';
}
*/
//错误的贪心，京师厚仁
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(m%2==1){
        int c=0;
        for(int i=0;i<n;i++){
            if(a[i][m/2]=='1') c++;
        }
        if(c>1){
            cout<<0<<'\n';
            return;
        }
    }
    vector<vector<pair<int,int>>> g(n);
    for(int j=0;j<m/2;j++){
        vector<int> r1,r2,rb;
        for(int i=0;i<n;i++){
            if(a[i][j]=='1' && a[i][m-j-1]=='1') rb.push_back(i);
            else if(a[i][j]=='1') r1.push_back(i);
            else if(a[i][m-j-1]=='1') r2.push_back(i);
        }
        if(rb.size()*2+r1.size()+r2.size()>2){
            cout<<0<<'\n';
            return;
        }
        if(r1.size()==2){
            g[r1[0]].push_back({r1[1],1});
            g[r1[1]].push_back({r1[0],1});
        }else if(r2.size()==2){
            g[r2[0]].push_back({r2[1],1});
            g[r2[1]].push_back({r2[0],1});
        }else if(r1.size()==1&&r2.size()==1){
            g[r1[0]].push_back({r2[0],0});
            g[r2[0]].push_back({r1[0],0});
        }
    }

    vector<int> c(n,-1);
    int res=1;
    for(int i=0;i<n;i++){
        if(c[i]==-1){
            c[i]=0;
            queue<int> q;
            q.push(i);
            bool ok=true;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto p:g[u]){
                    int v=p.first,w=p.second;
                    if(c[v]==-1){
                        c[v]=c[u]^w;
                        q.push(v);
                    }
                    else if(c[v]!=(c[u]^w)) ok=false;
                }
            }
            if(!ok){
                cout<<0<<'\n';
                return;
            }
            res=res*2%mod;
        }
    }
    cout<<res<<'\n';
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