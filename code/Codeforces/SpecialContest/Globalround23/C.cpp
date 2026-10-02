#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> id(n+1);



    iota(id.begin(),id.end(),0LL);

    auto find=[&](auto&& self,int x)->int{
        return x==id[x]?x:id[x]=self(self,id[x]);
    };


    auto merge=[&](int x,int y){
        x=find(find,x);
        y=find(find,y);
        if(x!=y){
            id[x]=y;
        }
    };
    
    vector<int> res(n+1);
    
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            int need=a[i-1]-a[i];
            int op=find(find,need);
            res[op]=i;
            merge(op,op+1);
        }
    }

    for(int i=1;i<=n;i++){
        if(!res[i]){
            res[i]=n;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';


    
    
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
