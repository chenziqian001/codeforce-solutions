#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    set<string>S;
    while(n--){
        string s,r="";
        cin>>s;
        for(char c:s){
            if(c=='u') r+="oo";
            else if(c=='h'){
                while(!r.empty()&&r.back()=='k') r.pop_back();
                r+='h';
            }else r+=c;
        }
        S.insert(r);
    }
    cout<<S.size()<<"\n";
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