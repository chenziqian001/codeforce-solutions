#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int ch[26];
    int cnt,ed;
    node(){
        memset(ch,-1,sizeof(ch));
        cnt=ed=0;
    }
} tr[1000010];

int idx;
int c[26][26];
int rk[26];
int pre;
void insert(string &s){
    int u=0,n=s.size();
    for(int i=0;i<n;i++){
        int cur=s[i]-'a';
        for(int t=0;t<26;t++){
            if(tr[u].ch[t]!=-1 && t!=cur) c[cur][t]+=tr[tr[u].ch[t]].cnt;
        }
        if(tr[u].ch[cur]==-1){
            tr[u].ch[cur]=++idx;
        }
        u=tr[u].ch[cur];
        tr[u].cnt++;
    }
    pre+=tr[u].cnt-1-tr[u].ed;
    tr[u].ed++;
}


void solve(){
    int n,q;
    cin>>n>>q;
    pre =0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    
    while(q--){
        string t;
        cin>>t;
        for(int i=0;i<26;i++){
            rk[t[i]-'a']=i;
        }
        int res=pre;
        for(int x=0;x<26;x++){
            for(int y=0;y<26;y++){
                if(rk[x]<rk[y]){
                    res+=c[x][y];
                }
            }
        }
        cout<<res<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}