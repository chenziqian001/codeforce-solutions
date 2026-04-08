#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int d=n+m-2;
    if(k<d||(k-d)%2!=0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<string> row(n,string(m-1,'R'));
    vector<string> col(n-1,string(m,'R'));
    
    row[0][0]='R';row[1][0]='R';
    col[0][0]='B';col[0][1]='B';
    
    char cur=(k-d)%4==2?'R':'B';
    
    for(int j=1;j<m-1;j++){
        row[0][j]=cur;
        cur=(cur=='R'?'B':'R');
    }
    for(int i=0;i<n-1;i++){
        col[i][m-1]=cur;
        cur=(cur=='R'?'B':'R');
    }
    
    
    char last=(cur=='R'?'B':'R');
    row[n-1][m-2]=(last=='R'?'B':'R');
    col[n-2][m-2]=last;
    row[n-2][m-2]=(last=='R'?'B':'R');
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++) cout<<row[i][j]<<" ";
        cout<<'\n';
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++) cout<<col[i][j]<<" ";
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}