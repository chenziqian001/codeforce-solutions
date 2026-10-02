/*
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int res=0;
    int n=s.size();
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            res++;
            s[i]='?';
            continue;
        }
        if(i>=2){
            if(s[i]==s[i-2]){
                res++;
                s[i]='?';
            }
        }
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int res=0;
    int n=s.size();
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]||(i>=2&&s[i]==s[i-2])){
            res++;
            for(char c='a';c<='z';c++){
                if(c!=s[i-1]&&(i<2||c!=s[i-2])&&(i+1>=n||c!=s[i+1])&&(i+2>=n||c!=s[i+2])){
                    s[i]=c;
                    break;
                }
            }
        }
    }
    cout<<res<<'\n'<<s<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
