#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    char c=s[0];
    int cur=1;
    int res=0;
    int ed=n;
    int ok=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]==c){
            cur++;
            ed=i;
        }
        else break;
    }
    for(int i=1;i<ed;i++){
        if(s[i]==c) cur++;
        else{
            res+=cur/2;
            if(cur%2==0) ok=1;
            cur=1;
            c=s[i];
        }
    }
    res+=cur/2;
    if(cur%2==0) ok=1;

    res-=ok;
    cout<<res<<'\n';
}




int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}