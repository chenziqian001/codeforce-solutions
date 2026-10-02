#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    vector<vector<int>> row(n+1,vector<int>(m+1));
    vector<vector<int>> col(n+1,vector<int>(m+1));
    
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+1<n){
                if(s[i][j]=='.' && s[i+1][j]=='.') col[i+1][j+1]=1; 
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j+1<m){
                if(s[i][j]=='.' && s[i][j+1]=='.') row[i+1][j+1]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            row[i][j]+=row[i-1][j]+row[i][j-1]-row[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            col[i][j]+=col[i-1][j]+col[i][j-1]-col[i-1][j-1];
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int val=row[x2][y2-1]+row[x1-1][y1-1]-row[x2][y1-1]-row[x1-1][y2-1];
        val+=col[x2-1][y2]+col[x1-1][y1-1]-col[x2-1][y1-1]-col[x1-1][y2];
        cout<<val<<'\n';
    }

}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}