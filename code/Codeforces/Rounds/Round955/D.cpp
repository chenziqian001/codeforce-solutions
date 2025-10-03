#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> b(n,vector<int>(m));
    int sum0=0;
    int sum1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            int x=c-'0';
            b[i][j]=x;
            if(x) sum1+=a[i][j];
            else sum0+=a[i][j];
        }
    }
    vector<vector<int>> pre(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pre[i][j]=b[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    int lr=n-k+1;
    int lc=m-k+1;
    vector<int> nums;
    for(int i=0;i<lr;i++){
        for(int j=0;j<lc;j++){
            int x2=i+k;
            int y2=j+k;
            int x1=i,y1=j;
            int num=pre[x2][y2]-pre[x1][y2]-pre[x2][y1]+pre[x1][y1];
            nums.push_back(num);
        }
    }
    int sz=nums.size();
    vector<int> gg;
    for(int i=0;i<sz;i++){
        int x=nums[i];
        int gap=abs(k*k-x-x);
        if(gap) gg.push_back(gap);
    }
    int gap=abs(sum0-sum1);
    if(gg.empty()){
        if(gap!=0) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
        return;
    }
    int g=gg[0];
    for(int i=1;i<gg.size();i++){
        g=__gcd(g,gg[i]);
    }
    if(gap%g==0){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }

}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}




