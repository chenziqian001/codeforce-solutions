#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct query{
    int l,r,id;
};
int counter[N];
int cnt;

void add(int x){
    if(x>N) return;
    if(counter[x]==x) cnt--;
    counter[x]++;
    if(counter[x]==x) cnt++;
}

void rem(int x){
    if(x>N) return;
    if(counter[x]==x) cnt--;
    counter[x]--;
    if(counter[x]==x) cnt++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<query> q(m);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        q[i]={l,r,i};
    }
    cnt=0;
    vector<int> res;
    int block=sqrt(n);
    sort(q.begin(),q.end(),[&](const query &x, const query &y){
        int bx=x.l/block,by=y.l/block;
        if(bx!=by){
            return bx<by;
        }
        else return x.r<y.r;
    });
    int L=0,R=-1;
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        while(R<q[i].r) add(a[++R]);
        while(R>q[i].r) rem(a[R--]);
        while(L<q[i].l) rem(a[L++]);
        while(L>q[i].l) add(a[--L]);
        ans[q[i].id]=cnt;
    }
    for(int x:ans){
        cout<<x<<'\n';
    }
}