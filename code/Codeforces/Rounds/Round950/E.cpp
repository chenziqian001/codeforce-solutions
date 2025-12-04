#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> b(n,vector<int>(m));

    vector<int> row(n*m);
    vector<int> col(n*m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]--;
            row[a[i][j]]=i;
            col[a[i][j]]=j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
            b[i][j]--;
        }
    }

    for(int i=0;i<n;i++){
        int r=row[b[i][0]];
        swap(a[r],a[i]);
        for(int j=0;j<m;j++){
            row[a[i][j]]=i;
            row[a[r][j]]=r;
        }
    }

    for(int j=0;j<m;j++){
        int c=col[b[0][j]];
        for(int i=0;i<n;i++){
            swap(a[i][c],a[i][j]);
            col[a[i][c]]=c;
            col[a[i][j]]=j;
        }
    }

    if(a==b){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}