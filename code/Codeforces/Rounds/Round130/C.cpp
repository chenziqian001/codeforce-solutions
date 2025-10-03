#include<bits/stdc++.h>
using namespace std;
#define int long long
int m;
vector<vector<int>> multi(vector<vector<int>> &a,vector<vector<int>> &b){
    int ra=a.size();
    int ca=a[0].size();
    int cb=b[0].size();
    vector<vector<int>> res(ra,vector<int>(cb,0));
    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            if(a[i][j]==0) continue;
            for(int k=0;k<cb;k++){
                res[i][k]=(res[i][k]+a[i][j]*b[j][k])%m;
            }
        }
    }
    return res;
}

vector<vector<int>> mp(vector<vector<int>> &init,int n,vector<vector<int>> &f0){
    vector<vector<int>> res=f0;
    vector<vector<int>> a=init;
    while(n){
        if(n&1) res=multi(res,a);
        a=multi(a,a);
        n>>=1;
    }
    return res;
}


signed main(){
    int l,r,k;
    cin>>m>>l>>r>>k;
    l--;
    vector<vector<int>> init(2,vector<int>(2));
    init[0][0]=1,init[0][1]=1,init[1][0]=1,init[1][1]=0;
    vector<vector<int>> f0(2,vector<int>(1));
    f0[0][0]=1,f0[1][0]=0;
    int g;
    for(int i=1;i*i<=r;i++){
        int j=r/i;
        if(r/j-l/j>=k){
            g=j;
            break;
        }
        if(r/i-l/i>=k){
            g=i;
        }
    }
    vector<vector<int>> res=mp(init,g-1,f0);
    cout<<res[0][0]%m<<'\n';
    system("pause");
    return 0;
}