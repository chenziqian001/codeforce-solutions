#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,q;
    if(!(cin>>n>>m>>q)) return;
    unordered_map<string,int> id;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        id[s]=i;
    }

    vector<int> fa(n),val(n,0);
    for(int i=0;i<n;i++) fa[i]=i;

    auto find=[&](auto& self,int x)->int{
        if(fa[x]==x) return x;
        int p=fa[x];
        int root=self(self,p);
        val[x]^=val[p];
        return fa[x]=root;
    };

    for(int i=0;i<m;i++){
        int type;
        string s1,s2;
        cin>>type>>s1>>s2;
        int u=id[s1],v=id[s2];
        int w=type-1;

        int ru=find(find,u),rv=find(find,v);
        if(ru==rv){
            if((val[u]^val[v])==w) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            cout<<"YES\n";
            fa[ru]=rv;
            val[ru]=w^val[u]^val[v];
        }
    }

    for(int i=0;i<q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int u=id[s1],v=id[s2];
        int ru=find(find,u),rv=find(find,v);

        if(ru!=rv) cout<<"3\n";
        else if((val[u]^val[v])==0) cout<<"1\n";
        else cout<<"2\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    //system("pause");
    return 0;
}