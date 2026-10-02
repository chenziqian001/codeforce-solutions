#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> c1(26);
    vector<int> c2(26);

    for(char c:s){
        if(isupper(c)){
            c2[c-'A']++;
        }
        else c1[c-'a']++;
    }

    int res=0;
    for(int i=0;i<26;i++){
        int x=min(c1[i],c2[i]);
        c1[i]-=x;
        c2[i]-=x;
        res+=x;
    }

    for(int i=0;i<26;i++){
        if(!k) break;
        int x=max(c1[i],c2[i]);
        int v=x/2;
        res+=min(k,v);
        k-=min(k,v);
    }
    cout<<res<<'\n';
    



    
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
