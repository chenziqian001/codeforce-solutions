#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int> st;
    string tmp="";
    int len=0;

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        st.insert(x);
        if(tmp==""){
            tmp=a[x];
            len=a[x].size();
        }
        else{
            if(a[x].size()!=len){
                cout<<"No"<<'\n';
                return;
            }
            for(int j=0;j<len;j++){
                if(tmp[j]!=a[x][j]) tmp[j]='?';
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(st.count(i)) continue;
        if(a[i].size()!=len) continue;
        bool ok=false;
        for(int j=0;j<len;j++){
            if(tmp[j]!=a[i][j] && tmp[j]!='?') ok=true;
        }
        if(!ok){
            cout<<"No"<<'\n';
            return;
        }
    }
    cout<<"Yes"<<'\n';
    cout<<tmp<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}