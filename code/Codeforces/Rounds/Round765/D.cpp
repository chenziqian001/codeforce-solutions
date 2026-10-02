#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }

    if(k==0){
        cout<<n<<"\n";
        for(int i=1;i<=n;i++)cout<<i<<" ";
        cout<<"\n";
        return;
    }

    sort(a.begin(),a.end());
    int p=63-__builtin_clzll(k);

    vector<int> ans;
    vector<array<int,2>> tr(35*n+5);
    vector<int> idx(35*n+5);
    int tt=1;
    for(int l=0,r=0;l<n;l=r){
        while(r<n && (a[l].first>>(p+1))==(a[r].first>>(p+1))) r++;
        int rt=tt++;
        bool ok=false;
        for(int i=l;i<r;i++){
            int x=a[i].first,id=a[i].second;
            if(i>l){
                int u=rt,res=0;
                for(int j=p;j>=0;j--){
                    int b=(x>>j)&1;
                    if(tr[u][b^1]){
                        res|=1<<j;
                        u=tr[u][b^1];
                    }else u=tr[u][b];
                }
                if(res>=k){
                    ans.push_back(id);
                    ans.push_back(idx[u]);
                    ok=true;
                    break;
                }
            }
            int u=rt;
            for(int j=p;j>=0;j--){
                int b=(x>>j)&1;
                if(!tr[u][b])tr[u][b]=tt++;
                u=tr[u][b];
            }
            idx[u]=id;
        }
        if(!ok) ans.push_back(a[l].second);
    }
    if(ans.size()<2){
        cout<<-1<<'\n';
    }
    else{
        cout<<ans.size()<<'\n';
        for(int x:ans){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
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

