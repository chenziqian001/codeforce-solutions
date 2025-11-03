#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> s={0};
    vector<int> ap((1<<20)+1);
    ap[0]=1;
    vector<vector<pair<int,int>>> ask(n);
    for(int i=0;i<q;i++){
        int l,x;;
        cin>>l>>x;
        l--;
        ask[l].emplace_back(x,i);
    }
    int res=1;
    vector<int> ans(q);
    for(int i=0;i<n;i++){
        if(ap[a[i]]){
            res=(res*2)%mod;
        }
        else{
            int tmp=s.size();
            for(int j=0;j<tmp;j++){
                s.push_back(a[i]^s[j]);
                ap[s.back()]=1;
            }
        }
        for(auto [x,id]:ask[i]){
            ans[id]=ap[x]*res%mod;
        }
    }


    for(int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
    //system("pause");
}