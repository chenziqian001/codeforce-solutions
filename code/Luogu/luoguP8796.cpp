#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;





void solve(){
    string s;
    cin>>s;
    
    int n=s.size();
    int m;cin>>m;

    vector<vector<int>> tag(4*n+1,vector<int>(26));

    auto build=[&](auto self,int p,int l,int r)->void{
        for(int i=0;i<26;i++)tag[p][i]=i;
        if(l==r)return;
        int mid=(l+r)>>1;
        self(self,p<<1,l,mid);
        self(self,p<<1|1,mid+1,r);
    };

    auto push_down=[&](int p){
        bool ok=false;
        for(int i=0;i<26;i++){
            if(tag[p][i]!=i){
                ok=true;
                break;
            }
        }
        if(!ok) return;
        for(int i=0;i<26;i++){
            tag[p<<1][i]=tag[p][tag[p<<1][i]];
            tag[p<<1|1][i]=tag[p][tag[p<<1|1][i]];
        }
        for(int i=0;i<26;i++) tag[p][i]=i;
    };

    auto update=[&](auto self,int p,int l,int r,int ql,int qr,int x,int y)->void{
        if(ql<=l&&r<=qr){
            for(int i=0;i<26;i++){
                if(tag[p][i]==x)tag[p][i]=y;
            }
            return;
        }
        push_down(p);
        int mid=(l+r)>>1;
        if(ql<=mid)self(self,p<<1,l,mid,ql,qr,x,y);
        if(qr>mid)self(self,p<<1|1,mid+1,r,ql,qr,x,y);
    };


   

    auto query=[&](auto self,int p,int l,int r)->void{
        if(l==r){
            s[l-1]=tag[p][s[l-1]-'a']+'a';
            return;
        }
        push_down(p);
        int mid=(l+r)/2;
        self(self,p*2,l,mid);
        self(self,p*2+1,mid+1,r);
    };

    build(build,1,1,n);
    while(m--){
        int l,r;
        char x,y;
        cin>>l>>r>>x>>y;
        if(x!=y){
            update(update,1,1,n,l,r,x-'a',y-'a');
        }
    }

    query(query,1,1,n);
    cout<<s<<'\n';
    


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
