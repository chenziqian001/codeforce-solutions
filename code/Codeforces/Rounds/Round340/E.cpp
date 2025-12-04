#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
#define int long long


int block;
struct query{
    int l,r,id;
    bool operator<(const query o) const{
        if(l/block!=o.l/block){
            return l<o.l;
        }
        else{
            if(l/block % 2){
                return r<o.r;
            }
            else{
                return r>o.r;
            }
        }
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    block=sqrt(n);

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^a[i-1];
    }
    vector<query> q(m);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--;
        q[i]={l,r,i};
    } 
    sort(q.begin(),q.end());

    int cnt[N];
    memset(cnt,0,sizeof(cnt));

    int sum=0;

    auto add=[&](int x){
        sum+=cnt[k^pre[x]];
        cnt[pre[x]]++;
    };
    auto del=[&](int x){
        cnt[pre[x]]--;
        sum-=cnt[k^pre[x]];
    };

    vector<int> res(m);

    int l=1,r=0;
    for(int i=0;i<m;i++){
        int tl=q[i].l;
        int tr=q[i].r;
        while(l<tl){
            del(l);
            l++;
        }
        while(l>tl){
            l--;
            add(l);
        }
        while(r<tr){
            r++;
            add(r);
        }
        while(r>tr){
            del(r);
            r--;
        }
        res[q[i].id]=sum;
    }
    for(int i=0;i<m;i++){
        cout<<res[i]<<'\n';
    }
    
    //system("pause");

}