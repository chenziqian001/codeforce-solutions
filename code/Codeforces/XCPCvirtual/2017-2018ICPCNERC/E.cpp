#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    string s;
    cin>>n>>s>>m;
    bool inS[256]={0};
    for(char c:s){
        if(c!='*')inS[c]=1;
    }
    vector<string>v;
    while(m--){
        string w;
        cin>>w;
        bool ok=1;
        for(int i=0;i<n;i++){
            if(s[i]!='*'&&w[i]!=s[i])ok=0;
            if(s[i]=='*'&&inS[w[i]])ok=0;
        }
        if(ok) v.push_back(w);
    }
    int ans=0;
    for(char c='a';c<='z';c++){
        if(inS[c]) continue;
        bool all=1;
        for(string w:v){
            bool has=0;
            for(char ch:w){
                if(ch==c)has=1;
            }
            if(!has){
                all=0;
                break;
            }
        }
        if(all)ans++;
    }
    cout<<ans<<"\n";
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