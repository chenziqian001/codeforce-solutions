#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,m;
    cin>>n>>m;
    

    vector<int> lst(m+1);
    vector<vector<int>> gp(n+1);
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        for(int j=0;j<p;j++){
            int x;
            cin>>x;
            lst[x]=i;
            gp[i].push_back(x);
        }
    }
    if(n==1){
        cout<<"No"<<'\n';
        return;
    }


    for(int i=1;i<n;i++){
        bool ok=true;
        for(int x:gp[i]){
            if(lst[x]==i+1){
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<"Yes"<<'\n';
            vector<int> res(n);
            iota(res.begin(),res.end(),1);
            swap(res[i-1],res[i]);
            for(int i=0;i<n;i++){
                cout<<res[i]<<(i==n-1?"":" ");
            }
            cout<<'\n';
            return;
        }
    }
    cout<<"No"<<'\n';
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
 