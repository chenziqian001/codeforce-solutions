#include<bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Hash{
    uint64_t h1,h2;
    bool operator<(const Hash& o)const{
        if(h1!=o.h1)return h1<o.h1;
        return h2<o.h2;
    }
    bool operator==(const Hash& o)const{
        return h1==o.h1&&h2==o.h2;
    }
};

struct Node{
    Hash h;
    int cnt,j,i;
    bool operator<(const Node& o)const{
        return h<o.h;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<uint64_t> r1(n),r2(n);
    for(int i=0;i<n;i++){
        r1[i]=rng();
        r2[i]=rng();
    }
    map<Hash,pair<int,int>> mp;
    for(int j=0;j<m;j++){
        uint64_t h1=0,h2=0;
        for(int i=0;i<n;i++){
            if(a[i][j]=='1'){
                h1^=r1[i];
                h2^=r2[i];
            }
        }
        Hash H={h1,h2};
        if(mp.find(H)==mp.end())mp[H]={1,j};
        else mp[H].first++;
    }
    vector<Node> v;
    for(auto& kv:mp){
        Hash H=kv.first;
        int c=kv.second.first,j=kv.second.second;
        for(int i=0;i<n;i++){
            Hash cand={H.h1^r1[i],H.h2^r2[i]};
            v.push_back({cand,c,j,i});
        }
    }
    sort(v.begin(),v.end());
    int mx=-1,bj=-1,bi=-1;
    for(int i=0;i<v.size();){
        int cur=0,st=i;
        while(i<v.size()&&v[i].h==v[st].h){
            cur+=v[i].cnt;
            i++;
        }
        if(cur>mx){
            mx=cur;
            bj=v[st].j;
            bi=v[st].i;
        }
    }
    cout<<mx<<"\n";
    string ans="";
    for(int i=0;i<n;i++){
        char ch=a[i][bj];
        if(i==bi)ch=(ch=='0'?'1':'0');
        ans+=ch;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if(cin>>t)while(t--)solve();
    return 0;
}