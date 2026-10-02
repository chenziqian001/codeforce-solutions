#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    unordered_map<string,int> st;
    vector<bool> ok(n,false);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a[i]=s;
        st[s]=i;
    }
    while(m--){
        string s;
        cin>>s;
        if(st.find(s)==st.end()){
            cout<<"WRONG"<<'\n';
            continue;
        }
        if(ok[st[s]]){
            cout<<"REPEAT"<<'\n';
        }
        else{
            ok[st[s]]=true;
            cout<<"OK"<<'\n';
        }
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