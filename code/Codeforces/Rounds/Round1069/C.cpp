#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    string t;
    cin>>s>>t;

    vector<int> cnt(26);
    int n=s.size();

    for(char c:s){
        cnt[c-'a']--;
    }
    for(char c:t){
        cnt[c-'a']++;
    }

    for(int i=0;i<26;i++){
        if(cnt[i]<0){
            cout<<"Impossible"<<'\n';
            return;
        }
    }

    vector<vector<pair<char,int>>> ins(n+1);

    for(int i=0;i<26;i++){
        if(!cnt[i]) continue;

        int j=0;
        int need=i;
        while(j<n&&(s[j]-'a')<=need){
            j++;
        }
        ins[j].push_back({char('a'+i),cnt[i]});
    }

    string res;

    for(int i=0;i<n;i++){
        for(auto [c,num]:ins[i]){
            res+=string(num,c);
        }
        res+=s[i];
    }

    for(auto [c,num]:ins[n]){
        res+=string(num,c);
    }

    cout<<res<<"\n";
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


