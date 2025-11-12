#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define i64 long long

struct node{
    i128 val;
    vector<int> cur;
};


void solve(){
    int n,q;
    cin>>n>>q;
    vector<node> a;
    a.push_back({0,{}});
    i128 len=0;
    for(int i=0;i<n;i++){
        int op,x;
        cin>>op>>x;
        if(len>1e18) continue;
        if(op==1){
            a.back().cur.push_back(x);
            len++;
        }
        else{
            len*=(x+1);
            a.push_back({len,{}});
        }
    }
    while(q--){
        i64 k;
        cin>>k;
        for(int i=a.size()-1;i>=0;i--){
            if(k>a[i].val){
                cout<<a[i].cur[k-a[i].val-1]<<" ";
                break;
            }
            k%=(a[i-1].val+a[i-1].cur.size());
            if(k==0) k=a[i-1].val+a[i-1].cur.size();
        }
    }
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}