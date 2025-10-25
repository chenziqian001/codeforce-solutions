#include<bits/stdc++.h>
using namespace std;
#define int long long
const int n=30;
int a[n];
int k;
int fuck(int x){
    if(x==0) return 0;
    //f[i][j][k][u] i->ith digi,j->sum of digi,k->is_equal?,u->exsist 4?
    vector<vector<vector<vector<int>>>> f(n,vector<vector<vector<int>>>(130,vector<vector<int>>(2,vector<int>(2))));
    for(int i=0;i<x/a[0];i++){
        f[0][i][0][i==4]=1;
    }
    f[0][x/a[0]][1][x/a[0]==4]=1;
    int cur=x;
    for(int i=0;i<n-1;i++){
        cur%=a[i];
        for(int j=0;j<130;j++){
            for(int k=0;k<2;k++){
                for(int u=0;u<2;u++){
                    if(!f[i][j][k][u]) continue;
                    for(int add=0;add<5;add++){
                        if(k && add>cur/a[i+1]) continue;
                        if(u && add>0) continue;
                        int nk= k&& add==cur/a[i+1];
                        int nu= u|| add==4;
                        f[i+1][j+add][nk][nu]+=f[i][j][k][u];
                    }
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            res+=f[n-1][k][i][j];
        }
    }
    return res;
}


void solve(){
    int l,r;
    cin>>l>>r>>k;
    if(k>120){
        cout<<0<<'\n';
        return;
    }
    cout<<fuck(r)-fuck(l-1)<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    a[n-1]=1;
    for(int i=n-2;i>=0;i--){
        a[i]=a[i+1]*4+1;
    }
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}




/*
1   1
101   5
10101  21
1010101   85
101010101   ....
*/


//要让数字尽可能的小，4这个数字在我们的斑马进制中就至多出现一次