#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;

int a[N];
int cnt[N];

int res;
int block;


struct query{
    int l,r,id;
    int block_l;

    bool operator<(const query other) const{
        if(block_l!=other.block_l){
            return block_l<other.block_l;
        }
        else{
            if(block_l%2==0){
                return r<other.r;
            }
            else{
                return r>other.r;
            }
        }
    }
};


void add(int pos){
    int s=a[pos];
    int k=cnt[s];
    res-=k*k*s;

    cnt[s]++;
    k++;

    res+=k*k*s;
}

void dele(int pos){
    int s=a[pos];
    int k=cnt[s];
    res-=k*k*s;

    cnt[s]--;
    k--;

    res+=k*k*s;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;

    block=sqrt(n);

    for(int i=0;i<n;i++) cin>>a[i];


    vector<query> q(t);

    for(int i=0;i<t;i++){
        cin>>q[i].l>>q[i].r;
        q[i].l--,q[i].r--;
        q[i].id=i;

        q[i].block_l=(q[i].l-1)/block;
    }

    sort(q.begin(),q.end());

    vector<int> ans(t);

    int l=0,r=-1;


    for(auto qq:q){
        int ql=qq.l;
        int qr=qq.r;

        while(l<ql){
            dele(l);
            l++;
        }
        while(l>ql){
            l--;
            add(l);
        }
        while(r<qr){
            r++;
            add(r);
        }
        while(r>qr){
            dele(r);
            r--;
        }
        ans[qq.id]=res;
    }

    for(int x:ans){
        cout<<x<<'\n';
    }
    //system("pause");

}