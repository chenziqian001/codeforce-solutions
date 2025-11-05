#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==2){
        cout<<(a[1]^a[2])<<'\n';
        return;
    }
    struct node{
        int nxt[2];
        int mx;
        node (int x){
            nxt[0]=nxt[1]=0;
            mx=x;
        }
    };
    vector<node> tr;
    auto insert=[&](int val,int id){
        int p=1;
        for(int i=29;i>=0;i--){
            int nx=((val>>i)&1);
            if(tr[p].nxt[nx]==0){
                int tmp=tr.size();
                tr.emplace_back(id);
                tr[p].nxt[nx]=tmp;
            }
            p=tr[p].nxt[nx];
            tr[p].mx=id;
        }
    };
    auto query=[&](int mid,int val){
        int p=1;
        int res=0;
        for(int i=29;i>=0;i--){
            if(!p) return res;
            int x=((mid>>i)&1);
            int y=((val>>i)&1);
            if(x && y){
                res=max(res,tr[tr[p].nxt[1]].mx);
                p=tr[p].nxt[0];
            }
            else if(x){
                res=max(res,tr[tr[p].nxt[0]].mx);
                p=tr[p].nxt[1];
            }
            else if(y){
                p=tr[p].nxt[1];
            }
            else{
                p=tr[p].nxt[0];
            }
        }
        return res;
    };

    int l=0,r=(1LL<<30)-1; 
    while(l<r){
        int mid=(l+r)/2;
        tr.clear();
        tr.emplace_back(-1); 
        tr.emplace_back(-1);
        int sum=0;
        int left=0;
        for(int i=1;i<=n;i++){
            left=max(left,query(mid,a[i]));
            sum+=left;
            insert(a[i],i);
        }
        if(sum>=k){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    l--;
    cout<<l<<'\n';
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