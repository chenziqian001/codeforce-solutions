#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int pre[N];
int bad[N];
vector<vector<pair<int,int>>> f(N,vector<pair<int,int>>(23));

void dc(int l,int r){
    if(l>=r) return;
    int k=__lg(r-l+1);
    int mid=max(f[l][k],f[r-(1<<k)+1][k]).second;

    dc(l,mid-1);
    dc(mid+1,r);

    int left=pre[mid-1]-pre[l-1];
    int right=pre[r]-pre[mid];

    if(a[mid]>left){
        bad[l]+=1;
        bad[mid]-=1;
    }

    if(a[mid]>right){
        bad[mid+1]+=1;
        bad[r+1]-=1;
    }
}


void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        f[i][0]={a[i],i};
        bad[i]=0;
    }

    for(int i=1;i<23;i++){
        for(int l=1;l+(1<<i)-1<=n;l++){
            f[l][i]=max(f[l][i-1],f[l+(1<<(i-1))][i-1]);
        }
    }

    dc(1,n);
    int res=0;
    for(int i=1;i<=n;i++){
        bad[i]+=bad[i-1];
        res+=!bad[i];
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