#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=INT_MAX;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,y,k;
    cin>>n>>m>>x>>y>>k;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int q[2001];
    int p=0;
    vector<vector<vector<int>>> f(2,vector<vector<int>>(n+1,vector<int>(m+1,0)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[p][i][j]=-inf;
        }
    }
    f[p][x][y]=0;
    int res=0;
    while(k--){
        p^=1;

  
        int s,t,d;
        cin>>s>>t>>d;
        int len=t-s+1;
        if(d==1){
            for(int j=1;j<=m;j++){
                int l=1,r=0;
                for(int i=n;i>=1;i--){
                    if(a[i][j]=='x'){
                        l=1,r=0;
                        continue;
                    }
                    while(l<=r && f[p^1][q[r]][j]+q[r]<=f[p^1][i][j]+i) r--;
                    while(l<=r && q[l]-i>len) l++;
                    q[++r]=i;
                    f[p][i][j]=f[p^1][q[l]][j]+q[l]-i;
                    res=max(res,f[p][i][j]);
                }
            }
        }
        else if(d==2){
            for(int j=1;j<=m;j++){
                int l=1,r=0;
                for(int i=1;i<=n;i++){
                    if(a[i][j]=='x'){
                        l=1,r=0;
                        continue;
                    }
                    while(l<=r && f[p^1][q[r]][j]-q[r]<=f[p^1][i][j]-i) r--;
                    while(l<=r && i-q[l]>len) l++;
                    q[++r]=i;
                    f[p][i][j]=f[p^1][q[l]][j]+i-q[l];
                    res=max(res,f[p][i][j]);
                }
            }
        }
        else if(d==3){
            for(int i=1;i<=n;i++){
                int l=1,r=0;
                for(int j=m;j>=1;j--){
                    if(a[i][j]=='x'){
                        l=1,r=0;
                        continue;
                    }
                    while(l<=r && f[p^1][i][q[r]]+q[r]<=f[p^1][i][j]+j) r--;
                    while(l<=r && q[l]-j>len) l++;
                    q[++r]=j;
                    f[p][i][j]=f[p^1][i][q[l]]+q[l]-j;
                    res=max(res,f[p][i][j]);
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                int l=1,r=0;
                for(int j=1;j<=m;j++){
                    if(a[i][j]=='x'){
                        l=1,r=0;
                        continue;
                    }
                    while(l<=r && f[p^1][i][q[r]]-q[r]<=f[p^1][i][j]-j) r--;
                    while(l<=r && j-q[l]>len) l++;
                    q[++r]=j;
                    f[p][i][j]=f[p^1][i][q[l]]+j-q[l];
                    res=max(res,f[p][i][j]);
                }
            }

        } 
    }
    cout<<res<<'\n';
    //system("pause");
    return 0;
}
