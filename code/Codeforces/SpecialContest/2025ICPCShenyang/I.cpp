#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    

    vector<vector<bool>> sol(500,vector<bool>(14,false));


    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c<240){
            if(sol[a][b]){
                cout<<0<<'\n';
                continue;
            }
            else{
                sol[a][b]=true;
                cout<<b<<'\n';
            }
        }
        else{
            int cnt=0;
            if(sol[a][b]){
                cout<<0<<'\n';
                continue;
            }
            
            for(int j=1;j<=13;j++){
                cnt+=sol[a][j]==true;
            }
            sol[a][b]=1;

            
           
           
            if(cnt<3){
                cout<<b<<'\n';
            }
            else cout<<0<<'\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}