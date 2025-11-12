#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;



void solve(){
    vector<string> a(8);
    for(int i=1;i<=7;i++){
        string s;
        cin>>s;
        s=" "+s;
        a[i]=s;
    }
    int res1=inf,res2=inf;
    function<void(int,int,int,int)> dfs=[&](int x,int y,int cnt,int gp){
        if(x==6){
            if(gp==0) res1=min(res1,cnt);
            else res2=min(res2,cnt);
            return;
        }
        if(y==6){
            dfs(x+1,1,cnt,gp);
            return;
        }
        if((x+y)%2!=gp){
            dfs(x,y+1,cnt,gp);
            return;
        }
        
        if(a[x][y]=='B' && a[x+2][y]=='B' && a[x][y+2]=='B' && a[x+1][y+1]=='B' &&a[x+2][y+2]=='B'){
            a[x][y+2]='W';
            dfs(x,y+1,cnt+1,gp);
            a[x][y+2]='B';

            a[x+1][y+1]='W';
            dfs(x,y+1,cnt+1,gp);
            a[x+1][y+1]='B';

            a[x+2][y]='W';
            dfs(x,y+1,cnt+1,gp);
            a[x+2][y]='B';
            
            a[x+2][y+2]='W';
            dfs(x,y+1,cnt+1,gp);
            a[x+2][y+2]='B';
        }
        else dfs(x,y+1,cnt,gp);

    };
    dfs(1,1,0,0);
    dfs(1,1,0,1);
    cout<<res1+res2<<'\n';
    
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