#include <bits/stdc++.h>
using namespace std;
#define int long long
int p;
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%p;
        a=a*a%p;
        n>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,p-2);
}



void solve(){
    int n,m;
    cin>>n>>m>>p;
    int iv=inv(m);
    vector<int> pw(n+1);
    pw[0]=1;
    for(int i=1;i<=n;i++){
        pw[i]=pw[i-1]*iv%p;
    }

    int res=0;
    for(int i=1;i<=n;i++){
        res=(res+(n-i+1)*pw[i/2]%p)%p;
    }

    res=res*res%p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i%2==j%2){
                int c=(n-max(i,j)+1);
                res=(res+p-c*pw[i/2+j/2]%p)%p;
                res=(res+c*pw[max(i,j)/2]%p)%p;
            }

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