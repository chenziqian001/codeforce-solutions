#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(m+1);
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        int len;
        cin>>len;
        for(int j=0;j<len;j++){
            int x;
            cin>>x;
            a[i].push_back(x);
            cnt[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(cnt[i]==0){
            cout<<"NO"<<'\n';
            return;
        }
    }
    int t=0;
    for(int i=0;i<n;i++){
        bool ok=true;
        for(int x:a[i]){
            if(cnt[x]==1){
                ok=false;
                break;
            }
        }
        if(ok) t++; 
    }


    if(t>=2){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}





