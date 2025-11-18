#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> fuck(vector<vector<int>> a,vector<vector<int>> b){
    int ra=a.size();
    int ca=a[0].size();
    int cb=b[0].size();
    vector<vector<int>> res(ra,vector<int>(cb));
    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            for(int k=0;k<cb;k++){
                res[i][k]=max(res[i][k],a[i][j]+b[j][k]);
            }
        }
    }
    return res;
}

vector<vector<int>> qp(vector<vector<int>> m,vector<vector<int>> f0,int n){
    vector<vector<int>> res=f0;
    while(n){
        if(n&1) res=fuck(res,m);
        m=fuck(m,m);
        n>>=1;
    }
    return res;
}


void solve(){
    int n,m,K,r;
    cin>>n>>m>>K>>r;
    vector<int> a(n);
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    } 

    vector<vector<int>> M(1<<n,vector<int>(1<<n));
    
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            int cost=0;
            int at=0;
            for(int k=0;k<n;k++){
                if(~(j>>k)&1) continue;
                at+=a[k];
                cost+=c[k]+(((i>>k)&1)?K:0);
            }
            if(cost>m) continue;
            M[i][j]=at;
        }
    }
    vector<vector<int>> f0(1<<n,vector<int>(1<<n));

    f0=qp(M,f0,r);
    int res=0;
    

    for(int i=0;i<(1<<n);i++){
        int tmp=0;
        for(int j=0;j<(1<<n);j++){
            tmp=max(tmp,f0[i][j]);
        }
        res=max(res,tmp);
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
/*
3
3 7 1 5
59 3
13 2
81 4
5 14 2 9
66 8
20 2
25 4
39 6
57 7
4 13 7 16
18 2
13 5
33 4
7 1
*/