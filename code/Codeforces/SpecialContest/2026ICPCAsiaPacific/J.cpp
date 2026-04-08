#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,d;
    cin>>n>>d;

    vector<int> a(n),b(n),pos(n+1),idx(n+1),p(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        idx[b[i]]=i;
    }
    for(int i=0;i<n;i++){
        p[i]=pos[b[i]];
    }

    int k=0;
    for(int i=0;i<n-1;i++){
        if(p[i]>p[i+1]){
            k++;
        }
    }
    cout<<p[n-1]+n*k-n+1<<'\n';
    for(int o=1;o<d;o++){
        int op,x,y;
        cin>>op>>x>>y;
        x--,y--;
        vector<int> tmp;
        if(op==1){
            int u=a[x],v=a[y];
            int i=idx[u],j=idx[v];
            tmp={i-1,i,j-1,j};
        }
        else{
            tmp={x-1,x,y-1,y};
        }

        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        for(int l=0;l<tmp.size();l++){
            int val=tmp[l];
            if(val>=0 && val<n-1 && p[val]>p[val+1]) k--;
        }

        if(op==1){
            int u=a[x],v=a[y];
            pos[u]=y;pos[v]=x;
            p[idx[u]]=y;p[idx[v]]=x;
            swap(a[x],a[y]);
        }else{
            int u=b[x],v=b[y];
            idx[u]=y;idx[v]=x;
            p[x]=pos[v];p[y]=pos[u];
            swap(b[x],b[y]);
        }

        for(int l=0;l<tmp.size();l++){
            int val=tmp[l];
            if(val>=0 && val<n-1 && p[val]>p[val+1]) k++;
        }
        cout<<p[n-1]+n*k-n+1<<'\n';
    }

}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}