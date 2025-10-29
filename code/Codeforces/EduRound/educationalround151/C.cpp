#include<bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int m;
    cin>>m;
    string l,r;
    cin>>l>>r;
    vector<vector<int>> nxt(n+2,vector<int>(10,n+1));
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<10;j++){
            nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i]-'0']=i+1;
        }
    }
    int pos=0;
    for(int i=0;i<m;i++){
        int far=-1;
        for(int j=l[i]-'0';j<=r[i]-'0';j++){
            if(nxt[pos][j]==n+1){
                cout<<"YES"<<'\n';
                return;
            }
            far=max(far,nxt[pos][j]);
        }
        pos=far;
        if(pos>n && i<m-1){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}