#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k,p,m;
    cin>>n>>k>>p>>m;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==n){
        cout<<m/a[p]<<'\n';
        return;
    }

    int val=0;
    for(int i=1;i<=n;i++){
        if(i==p){
            val=a[i];
        }
    }

    priority_queue<int,vector<int>,greater<int>> ink;
    queue<int> out;
    for(int i=1;i<=k;i++){
        if(i==p) continue;
        ink.push(a[i]);
    }
    for(int i=k+1;i<=n;i++){
        if(i==p) continue;
        out.push(a[i]);
    }

    int res=0;
    int dis=max(0LL,p-k);
    if(dis==0){
        if(m>=val){
            res++;
            m-=val;
            dis=out.size();
            
            int node=out.front();
            out.pop();
            ink.push(node);  
        }
    }
    while(1){
        bool ok=true;
        while(dis>0){
            int node=ink.top();
            if(m>=node){
                m-=node;
                dis--;
                ink.pop();
                out.push(node);
                
                if(dis>0){ 
                    int nnode=out.front();
                    out.pop();
                    ink.push(nnode);
                }
            }
            else{
                ok=false;
                break;
            }
        }
        if(!ok) break;
        if(m>=val){
            m-=val;
            res++;
            dis=out.size();
            int nnode=out.front();
            out.pop();
            ink.push(nnode);
        }
        else{
            break;
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
