#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;


int f[N];
int a[N];
int n;


void add(int pos,int val){
    for(int i=pos;i<=n;i+=(i&-i)){
        f[i]+=val;
    }
}

int query(int pos){
    int res=0;
    for(int i=pos;i>0;i-=(i&-i)){
        res+=f[i];
    }

    return res;
}

bool check(int val,int k){
    return val*k<=query(k);
}


void solve(){
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> ask(n+1);
    for(int i=1;i<=n;i++){
        int l=1,r=n;
        int res=1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(a[i],mid)){
                l=mid+1;
            }
            else{
                r=mid-1;
                res=mid;
            }
        }
        add(res,1);
        ask[i]=res;
    }


    while(q--){
        int pos,x;
        cin>>pos>>x;
        if(ask[pos]<=x){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
    }

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}