#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> s(n+1),v;
    v.push_back(0);

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i%2) s[i]=s[i-1]+x;
        else s[i]=s[i-1]-x;
        v.push_back(s[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int m=v.size();
    vector<int> fw0(m+1),fw1(m+1);

    auto add=[&](vector<int>& fw,int i,int val){
        for(;i<=m;i+=i&-i) fw[i]+=val;
    };
    auto que=[&](vector<int>& fw,int i){
        int sum=0;
        for(;i>0;i-=i&-i) sum+=fw[i];
        return sum;
    };
    
    int res=0;
    for(int i=0;i<=n;i++){
        int p=lower_bound(v.begin(),v.end(),s[i])-v.begin()+1;
        if(i%2){
            res+=que(fw0,p-1);
            add(fw1,p,1);
        }
        else{
            res+=que(fw1,m)-que(fw1,p);
            add(fw0,p,1);
        }
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
