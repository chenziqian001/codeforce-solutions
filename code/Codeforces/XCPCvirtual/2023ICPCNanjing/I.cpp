#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> op(m);
    for(int i=0;i<m;i++){
        cin>>op[i].first>>op[i].second;
    }
    sort(op.begin(),op.end());

    int cur=0;
    int st=0;
    for(int i=0;i<m;i++){
        int x=op[i].first-cur;
        int val=op[i].second;   
        if(st+x!=val && val+1>x){
            cout<<"No"<<'\n';
            return;
        }
        cur=op[i].first;
        st=op[i].second;
    }
    cout<<"Yes"<<'\n';

    
 
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
 