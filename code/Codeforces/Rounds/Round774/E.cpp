#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<int> st(max(n,m)*25);
    vector<int> vis(max(n,m)+10);
    vector<int> mp(25);
    int cnt=0;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=m;j++){
            if(!st[i*j]) cnt++;
            st[i*j]=1;
        }
        mp[i]=cnt;
    }


    int res=1;
    for(int i=2;i<=n;i++){
        if(vis[i]) continue;
        int j=1;
        while(pow(i,j)<=n){
            vis[(long long)pow(i,j)]=1;
            j++;
        }
        j--;
        res+=mp[j];
    }
    cout<<res<<'\n';
    return 0;

}