#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> vis(n+1), fw(n+1);
    auto add=[&](int pos,int val){
        for(int i=pos;i<=n;i+=i&-i) fw[i]+=val;
    };
    auto get=[&](int pos){
        int res=0;
        for(int i=pos;i>0;i-=i&-i) res+=fw[i];
        return res;
    };

    int mx=a[0];
    add(a[0],1);
    vis[a[0]]=1;
    
    int fq=1, first_dup=-1;
    int cur=0;
    cout<<cur;
    
    for(int i=1;i<n;i++){
        if(a[i]<=mx){
            if(a[i]==mx){
                fq++;
                if(fq==2) first_dup=i; 
            }
            cur+=get(n)-get(a[i]);
        }
        else{
            cur+=2;
            if(fq>1){
                cur+=i-first_dup; 
            }
            mx=a[i];
            fq=1;
        }
        
        if(!vis[a[i]]){
            add(a[i],1);
            vis[a[i]]=1;
        }
        cout<<" "<<cur;
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
