#include<bits/stdc++.h>
using namespace std;
#define int long long


int ask(int i,int j,int x){
    int res;
    cout<<'?'<<" "<<i<<" "<<j<<" "<<x<<endl;
    cin>>res;
    return res;
}


 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> s(n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }

    vector<vector<int>> f(n+2,vector<int>(2*n+1));

    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int t=r-l;
            f[l][t]=max(f[l][t],s[r]-s[l-1]);
            f[r][t]=max(f[r][t],s[r]-s[l-1]);
        }
    }

    for(int i=0;i<2*n;i++){
        for(int j=1;j<=n;j++){
            int val=f[j][i];
            f[j][i+1]=max(f[j][i+1],val);
            f[j-1][i+1]=max(f[j-1][i+1],val);
            f[j+1][i+1]=max(f[j+1][i+1],val);
        }
    }

    int res=0;
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=2*n;j++){
            tmp^=(j*f[i][j]);
        }
        tmp+=i;
        res^=tmp;
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
 
 