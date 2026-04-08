#include<bits/stdc++.h>
using namespace std;
#define int long long

int pr[2000];
int cnt,res;

void dfs(int i,int k,bool f,int n){
    if(i==cnt){
        if(f) res+=n/k;
        else res-=n/k;
        return;
    }

    dfs(i+1,k,f,n);
    dfs(i+1,k*pr[i],!f,n);
}



int calc(int n,int p){
    res=cnt=0;
    for(int i=2;i*i<=p;i++){
        if(p%i==0){
            pr[cnt++]=i;
            while(p%i==0){
                p/=i;
            }
        }
    }
    if(p>1) pr[cnt++]=p;
    dfs(0,1,1,n);
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,p,k;
        cin>>x>>p>>k;
        int l=x+1,r=1e15;
        int del=calc(x,p);
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if((calc(mid,p)-del)>=k){
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        cout<<ans<<'\n';
    }
    //system("pause");
    return 0;
}