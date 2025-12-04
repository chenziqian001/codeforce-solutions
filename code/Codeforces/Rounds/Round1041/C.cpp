#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(n,vector<int>(2,-1));
    for(int i=0;i<n;i++) cin>>a[i][0];
    for(int i=0;i<n;i++) cin>>a[i][1];

    sort(a.begin(),a.end(),[&](vector<int> &x,vector<int> &y){
        return x[0]<y[0]; 
    });

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(a[i][0]-a[i][1]);
    }
    int res=sum;
    
    vector<int> gp;
    for(int i=1;i<n;i++){
        gp.clear();
        int tmp=sum-abs(a[i][0]-a[i][1])-abs(a[i-1][0]-a[i-1][1]);
        
        for(int j=i-1;j<=i;j++){
            for(int k=0;k<2;k++){
                gp.push_back(a[j][k]);
            }
        }
        
        sort(gp.begin(),gp.end());
        tmp+=gp[3]+gp[2]-gp[1]-gp[0];
        if(i==1) res=tmp;
        res=min(res,tmp);
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