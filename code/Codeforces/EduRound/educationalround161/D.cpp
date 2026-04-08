#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),d(n),l(n),r(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>d[i];
    
    for(int i=0;i<n;i++){
        l[i]=i-1;
        r[i]=i+1;
    }
    r[n-1]=-1;
    vector<int> v(n);
    iota(v.begin(),v.end(),0);
    vector<int> vis(n,-1);
    
    for(int i=0;i<n;i++){
        vector<int> die;
        for(int x:v){
            int sum=0;
            if(l[x]!=-1){
                sum+=a[l[x]];
            }
            if(r[x]!=-1){
                sum+=a[r[x]];
            }
            if(sum>d[x]){
                die.push_back(x);
            }
        }
        v.clear();
        cout<<die.size()<<" ";
        for(int x:die){
            vis[x]=i;
        }
        for(int x:die){
            if(l[x]!=-1){
                r[l[x]]=r[x];
                if(vis[l[x]]<i){
                    v.push_back(l[x]);
                    vis[l[x]]=i;
                }
            }
            if(r[x]!=-1){
                l[r[x]]=l[x];
                if(vis[r[x]]<i){
                    v.push_back(r[x]);
                    vis[r[x]]=i;
                }
            }
        }
    }
    cout<<'\n';


    
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