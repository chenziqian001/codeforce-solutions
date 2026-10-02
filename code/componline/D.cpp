#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;


int sim(int a,int b,vector<int> c){
    int res=1;
    while(a>0 || b>0){
        if(a>b){
            int x=c[a];
            b-=x;
            a-=1;
            if(a<0 || b<0) return 0;
            c[b]-=1;
        }
        else if(a<b){
            int x=c[b];
            a-=x;
            b-=1;
            if(a<0 || b<0) return 0;
            c[a]-=1;
        }
        else{
            if(c[a]==0) return 0;
            res=res*2%mod;
            int x=c[a];
            b-=x;
            a-=1;
            if(a<0 || b<0) return 0;
            c[b]-=1;
        }
    }
    return c[0]==0?res:0;
}


void solve(){
    int n;
    cin>>n;
    vector<int> c(n+2);
    int s=0;
    bool ok=true;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>n) ok=false;
        else c[x]++;
        s+=x;
    }
    if(!ok){
        cout<<0<<'\n';
        return;
    }

    int res=0;
    for(int a=0;a<=n;a++){
        int b=n-a;
        if((a*b)==s){
            res=(res+sim(a,b,c))%mod;
        }
    }
    cout<<res<<'\n';
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

