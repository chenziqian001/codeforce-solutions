#include<bits/stdc++.h>
using namespace std;
#define int long long

bool ok(string s){
    int n=s.size();
    for(int i=1;i<n-1;i++){
        if(s[i]=='i' && s[i-1]=='b' && s[i+1]=='e'){
            return true;
        }
    }
    return false;
}



void solve(){
    int n;
    cin>>n;
    set<string> st;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        bool get=false;
        for(int j=0;j<m;j++){
            string s;
            cin>>s;
            if(ok(s) && !st.count(s)){
                cout<<s<<'\n';
                st.insert(s);
                get=true;
            }
        }
        if(!get){
            cout<<"Time to play Genshin Impact, Teacher Rice!"<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}