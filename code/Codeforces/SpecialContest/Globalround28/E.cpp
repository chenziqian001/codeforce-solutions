#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    if(m>=2*n){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++){
            int d=(j-i+2*n)%(2*n);
            cout<<(d/2)+1<<(j==m-1?"":" ");
        }
        cout<<"\n";
    }

    
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

