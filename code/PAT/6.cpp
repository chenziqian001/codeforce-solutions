#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    vector<int> res(11);
    int id=0;
    while(id<11){
        string s="";
        if(cin>>s){
            res[id]=s.size();
        }
        else{
            res[id]=0;
        }
        id++;
    }
    for(int i=0;i<11;i++){
        cout<<res[i];
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