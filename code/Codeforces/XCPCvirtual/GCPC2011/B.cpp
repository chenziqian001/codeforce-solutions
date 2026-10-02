#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    set<int> st={'a','e','i','o','u'};
    string s;
    cin>>s;
    int n=s.size();
    int pos=-1;
    for(int i=n-1;i>=0;i--){
        if(st.count(s[i])){
            pos=i;
            break;
        }
    }
    for(int i =0;i<=pos;i++){
        cout<<s[i];
    }
    cout<<"ntry"<<'\n';
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