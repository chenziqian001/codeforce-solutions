#include<bits/stdc++.h>
using namespace std;


int fuck(string s){
    int cnt=0;
    for(int i=0;(int) i<s.size();){
        if(s[i]=='0') i++;
        else{
            cnt++;
            i+=3;
        }
    }
    return cnt;
}
 
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long res=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            res+=fuck(s.substr(i,j-i+1));
        }
    }
    cout<<res<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}


