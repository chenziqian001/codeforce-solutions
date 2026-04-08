#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int c0=0,c1=0;
    for(char c:s){
        if(c=='0') c0++;
        else c1++;
    }
    if(c0!=c1){
        cout<<-1<<'\n';
        return;
    }



    vector<int> res;
    int pos=0;


    while(s.size()){
        if(s[0]!=s.back()){
            s=s.substr(1,s.size()-2);
            pos++;
        }
        else if(s[0]=='0'){
            res.push_back(pos+s.size());
            pos++;
            s=s.substr(1)+'0';
        }
        else{
            res.push_back(pos);
            pos++;
            s='1'+s.substr(0,s.size()-1);
        }
    }


    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x<<" "; 
    }
    cout<<'\n';
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