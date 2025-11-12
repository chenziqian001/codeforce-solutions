#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;
const int N=2e5+10;
int q[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<vector<int>> f(2,vector<int>(2*n+1,inf));
    f[0][0]=0;
    int p=0;
    for(int i=1;i<=k;i++){
        int L,R;
        cin>>L>>R;
        p^=1;
        for(int j=0;j<=n;j++){
            f[p][j]=f[p^1][j];
        }
        int l=1,r=0;
        for(int j=0;j<=R;j++){
            if(j<=n){
                while(l<=r && f[p^1][j]<=f[p^1][q[r]]) r--;
                q[++r]=j;
            }
            while(l<=r && q[l]<j-(R-L)) l++;
            if(l<=r) f[p][j]=min(f[p][j],f[p^1][q[l]]+2);
        }
        l=1,r=0;
        for(int j=R;j>=0;j--){
            if(R-j<=n){
                while(l<=r && f[p^1][R-j]<=f[p^1][q[r]]) r--;
                q[++r]=R-j;
            }
            while(l<=r && q[l]<R-j-(R-L)) l++;
            //这里直接写q[l]<L-j的要不就是从别人里抄的，自己也不懂，要不就是没想让读者看懂
            if(l<=r) f[p][j]=min(f[p][j],f[p^1][q[l]]+1);
        }
    }

    if(f[p][n]>=inf){
        cout<<"Hungry"<<'\n';
    }
    else{
        cout<<"Full"<<'\n';
        cout<<f[p][n]<<'\n';
    }
    //system("pause");
    return 0;

}