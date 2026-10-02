#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;

    
    if(k<n || k>n*n-n+1){
        cout<<"No"<<'\n';
        return;
    }
    cout<<"Yes"<<'\n';
    vector<vector<int>> res(n,vector<int>(n,0));
    vector<bool> use(n*n+1,false);
    res[0][0]=k;
    use[k]=true;
    int id=k+1;
    for(int i=1;i<n;i++){
        res[i][i]=id++;
        use[id-1]=true;
    }
    id=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            while(use[id]) id++;
            if(!res[i][j]){
                res[i][j]=id++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<'\n';
    }
    



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


