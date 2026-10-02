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


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,n;
    cin>>x>>n;
    int res=1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0,tmp=n;
            while(tmp){
                cnt=cnt+tmp/i;
                tmp/=i;
            }
            res=res*qp(i,cnt)%mod;
            while(x%i==0) x/=i;
        }
    }

    if(x>1){
        int cnt=0,tmp=n;
        while(tmp){
            cnt=cnt+tmp/x;
            tmp/=x;
        }
        res=res*qp(x,cnt)%mod;
    }
    cout<<res<<'\n';
    //system("pause");
}

