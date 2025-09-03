#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int get_row(int x){
    return (x-1)/m;
}
void solve(){
    cin>>n>>m>>k;
    vector<int> a(n*m);
    vector<vector<int>> cnt(n);
    for(int i=0;i<n*m;i++){
        int x;
        cin>>x;
        a[i]=get_row(x);
    }
    if(k>=m){
        cout<<m<<'\n';
        return;
    }  
    int res=m*n;
    for(int i=0;i<n*m;i++){
        cnt[a[i]].push_back(i);
        if(cnt[a[i]].size()==m){
            int pos=max(m-1,cnt[a[i]][m-k-1]);
            res=min(res,pos+1);
        }
    }
    cout<<res<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}