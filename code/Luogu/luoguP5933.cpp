#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;








signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> c(n,vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c[i][j];
        }
    }

    vector<int> g(1<<n,1);
    vector<int> f(1<<n);

    for(int s=0;s<(1<<n);s++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((s>>i&1) &&(s>>j&1)){
                    g[s]=g[s]*(c[i][j]+1)%mod;
                }
            }
        }
    }

    auto lowbit=[&](int s){
        return s&(-s);
    };

    for(int s=0;s<(1<<n);s++){
        f[s]=g[s];
        for(int t=s;t;t=(t-1)&s){
            if(t!=s && t&lowbit(s)){
                f[s]=(f[s]-f[t]*g[s^t]%mod+mod)%mod;
            }
        }
    }

    cout<<f[(1<<n)-1]<<'\n';



    //system("pause");
}
