#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    for(char c='a';c<='z';c++){
        int p1=-1,p2=-1;
        for(int i=0;i<n;i++){
            if(s[i]==c && p1==-1) p1=i;
        }
        for(int i=0;i<m;i++){
            if(t[i]==c && p2==-1) p2=i;
        }
        if(p1==-1 || p2==-1) continue;
        vector<bool> c1(26,false);
        vector<bool> c2(26,false);
        for(int i=0;i<max(n,m);i++){
            if(i>p1 && i<n){
                c1[s[i]-'a']=true;
            }
            if(i>p2 && i<m){
                c2[t[i]-'a']=true;
            }
        }
        for(int i=0;i<26;i++){
            if(c1[i] && c2[i]){
                cout<<c<<(char)(i+'a')<<'\n';
                return;
            }
        }
    }
    cout<<"HENG!"<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

