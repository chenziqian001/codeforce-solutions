#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    vector<vector<int>> p(n,vector<int>(m));
    vector<int> c(n*m+1);
    int c0=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p[i][j];
            if(!p[i][j]){
                c0++;
            }
            else{
                c[p[i][j]]++;
            }
        }
    }

    vector<int> v;
    for(int i=1;i<=n*m;i++){
        if(c[i]) v.push_back(c[i]);
    }

    sort(v.rbegin(),v.rend());
    int sum=0;
    for(int x:v){
        sum+=x*a;
    }

    int res=sum;
    int save=0;

    for(int i=0;i<v.size();i++){
        if(i*b>=a) break;
        save+=v[i]*(a-i*b);   
        res=min(res,sum+(i+1)*b*c0-save);
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0; 
}