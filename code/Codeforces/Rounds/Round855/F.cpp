#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> m(n),h(n);
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        for(char c:s) {
            int v=c-'a';
            m[i]^=(1<<v);
            h[i]|=(1<<v);
        }
    }

    vector<int> c(1<<26);
    long long res=0;
    for(int j=0;j<26;j++){
        int tg=((1<<26)-1)^(1<<j);
        for(int i=0;i<n;i++){
            if(!(h[i] & (1<<j))){
                res+=c[tg^m[i]];
                c[m[i]]++;
            }
        }
        for(int i=0;i<n;i++) {
            if(!(h[i] & (1 << j))) {
                c[m[i]]--;
            }
        }
    }
    cout<<res<<'\n';
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
