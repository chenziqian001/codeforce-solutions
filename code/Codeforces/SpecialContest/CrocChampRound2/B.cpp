#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;


int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}


void solve(){
    string s,t;
    int k;
    cin>>s>>t>>k;
    string ss=s+s;
    ss.pop_back();
    int cnt=0;
    
    int n=t.size();
    vector<int> pi(n+1);
    for(int i=1,j=0;i<n;i++){
        while(j && t[i]!=t[j]) j=pi[j];
        if(t[i]==t[j]) j++;
        pi[i+1]=j;
    }

    for(int i=0,j=0;i<ss.size();i++){
        while(j && ss[i]!=t[j]) j=pi[j];
        if(t[j]==ss[i]) j++;
        if(j==n){
            cnt++;
            j=pi[j];
        }
    }
    int f;
    if(s==t){
        f=1;
    }
    else f=0;

    for(int i=1;i<=k;i++){
        f=(f*(-1)+qp(n-1,i-1)*cnt%mod+mod)%mod;
    }
    cout<<f<<'\n';





}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
}