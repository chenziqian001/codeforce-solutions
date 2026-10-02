#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> po,pc;
    for(int i=0;i<n;i++) {
        if(s[i] == '(') po.push_back(i);
        else pc.push_back(i);
    }
    int mini=n+1;
    string res ="";
    int lim=min(k,(int)po.size());
    for(int x=0;x<=lim;x++) {
        int y=min(k-x,(int)pc.size());
        string cur(n,'0');
        for(int i=0;i<x;i++) cur[po[i]] = '1';
        for(int i=0;i<y;i++) cur[pc[pc.size()-1-i]]='1';
        int m=0,op=0;
        for(int i=0;i<n;i++) {
            if(cur[i]=='1') continue;
            if(s[i]=='(') op++;
            else if(op>0) {
                op--;
                m++;
            }
        }
        if(m<mini){
            mini=m;
            res=cur;
        }
    }
    cout<<res<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    //system("pause");
    return 0;
}