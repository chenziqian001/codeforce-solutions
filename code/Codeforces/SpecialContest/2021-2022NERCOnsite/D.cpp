#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    string s,t;
    cin>>s>>t;

    vector<vector<int>> pos1(26);
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        pos1[c-'A'].push_back(i);
    }

    vector<int> cnt(26);
    for(char c:t){
        cnt[c-'A']++;
    }
    int lst=-1;
    for(int i=0;i<t.size();i++){
        int rem=cnt[t[i]-'A'];
        if(rem>pos1[t[i]-'A'].size()){
            cout<<"NO"<<'\n';
            return;
        }
        int cur=pos1[t[i]-'A'][pos1[t[i]-'A'].size()-rem];
        if(cur<lst){
            cout<<"NO"<<'\n';
            return;
        }
        lst=cur;
        cnt[t[i]-'A']--;
    }
    cout<<"YES"<<'\n';
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