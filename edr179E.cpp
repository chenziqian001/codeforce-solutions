#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<queue>
#include<set>
using namespace std;

#define int long long

void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<vector<set<int>>> st(3,vector<set<int>>(3));
    for(int i=0;i<q;i++){
        char x,y;
        cin>>x>>y;
        st[x-'a'][y-'a'].insert(i);
    } 

    for(int i=0;i<n;i++){
        if(s[i]=='a') continue;
        if(s[i]=='b'){
            if(!st[1][0].empty()){
                s[i]='a';
                st[1][0].erase(st[1][0].begin());
                continue;
            }
            if(!st[1][2].empty()){
                auto x=*st[1][2].begin();
                auto y=st[2][0].lower_bound(x);
                if(y!=st[2][0].end()){
                    s[i]='a';
                    st[1][2].erase(x);
                    st[2][0].erase(y);
                }
            }
        }
        else{
            if(!st[2][0].empty()){
                s[i]='a';
                st[2][0].erase(st[2][0].begin());
                continue;
            }
            if(!st[2][1].empty()){
                auto x=*st[2][1].begin();
                s[i]='b';
                st[2][1].erase(x);
                auto y=st[1][0].lower_bound(x);
                if(y!=st[1][0].end()){
                    s[i]='a';
                    st[1][0].erase(y);
                }  
            }
        }
    }

    cout<<s<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}