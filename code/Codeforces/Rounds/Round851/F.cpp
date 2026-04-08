#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,q;
    cin>>n>>q;
    
    vector<int> pa(n+1);
    vector<int> d(n+1);
    vector<int> deg(n+1);
    vector<pair<int,int>> e;
    iota(pa.begin()+1,pa.end(),1);


    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        e.emplace_back(u,v);
    }

    function<int(int)> find=[&](int x)->int{
        if(pa[x]==x) return x;
        int root=find(pa[x]);
        d[x]^=d[pa[x]];
        return pa[x]=root;
    };

    for(int i=0;i<q;i++){
        int u,v,x;
        cin>>u>>v>>x;
        int ru=find(u),rv=find(v);
        if(ru==rv){
            if((d[u]^d[v])!=x){
                cout<<"No"<<'\n';
                return;
            }
        }
        else{
            pa[ru]=rv;
            d[ru]=x^d[u]^d[v];
        }
    }


    cout<<"Yes"<<'\n';
    vector<int> odd(n+1);
    vector<int> sum(n+1);
    for(int i=1;i<=n;i++){
        if(deg[i]%2==1){
            int r=find(i);
            odd[r]++;
            sum[r]^=d[i];
        }
    }


    vector<int> f(n+1);


    int id=-1;
    for(int i=1;i<=n;i++){
        int rt=find(i);
        if(odd[rt]%2==1){
            id=rt;
            break;   
        }
    }
    int tt=0;
    for(int i=1;i<=n;i++){
        tt^=sum[i];
    }
    if(id!=-1){
        for(int i=1;i<=n;i++){
            int rt=find(i);
            if(rt==id){
                f[i]=tt;
            }
        }
    }

    vector<int> res(n+1);
    for(int i=1;i<=n;i++){
        res[i]=d[i]^f[i];
    }

    for(auto ee:e){
        cout<<(res[ee.first]^res[ee.second])<<" ";
    }
    cout<<'\n';

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