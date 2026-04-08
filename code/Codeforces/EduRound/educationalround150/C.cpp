#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int n=s.size();

    int val[5]={1,10,100,1000,10000};
    vector<int> l(5,-1);
    vector<int> r(5,-1);
    for(int i=0;i<n;i++){
        int id=s[i]-'A';
        r[id]=i;
    }
    for(int i=n-1;i>=0;i--){
        int id=s[i]-'A';
        l[id]=i;
    }
    
    int res=0;
    vector<int> init_vis(5);
    for(int pos=n-1;pos>=0;pos--){
        int cur=s[pos]-'A';
        bool ok=false;
        for(int big=cur+1;big<5;big++){
            if(init_vis[big]) ok=true;
        }
        if(ok) res-=val[cur];
        else res+=val[cur];
        init_vis[cur]=1;
    }

    for(int i=0;i<5;i++){
        if(r[i]==-1) continue;
        for(int j=0;j<i;j++){
            s[r[i]]=j+'A';
            int tmp=0;
            vector<int> vis(5);
            for(int pos=n-1;pos>=0;pos--){
                int cur=s[pos]-'A';
                bool ok=false;
                for(int big=cur+1;big<5;big++){
                    if(vis[big]) ok=true;
                }
                if(ok){
                    tmp-=val[cur];
                }
                else{
                    tmp+=val[cur];
                }
                vis[cur]=1;
            }
            res=max(res,tmp);
            s[r[i]]=i+'A';
        }
    }

    for(int i=0;i<5;i++){
        if(l[i]==-1) continue;
        for(int j=i+1;j<5;j++){
            s[l[i]]=j+'A';
            int tmp=0;
            vector<int> vis(5);
            for(int pos=n-1;pos>=0;pos--){
                int cur=s[pos]-'A';
                bool ok=false;
                for(int big=cur+1;big<5;big++){
                    if(vis[big]) ok=true;
                }
                if(ok){
                    tmp-=val[cur];
                }
                else{
                    tmp+=val[cur];
                }
                vis[cur]=1;
            }
            res=max(res,tmp);
            s[l[i]]=i+'A';
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
    return 0;
}