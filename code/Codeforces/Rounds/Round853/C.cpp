#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int get(int c){
    return m*(m+1)/2-(m-c)*(m-c+1)/2;
}
void solve(){
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> appear(n+m+1,-1);
    vector<int> cnt(n+m+1);
    for(int x:a){
        appear[x]=0;
    }

    for(int i=1;i<=m;i++){
        int pos,val;
        cin>>pos>>val;
        cnt[a[pos]]+=i-appear[a[pos]];
        appear[a[pos]]=-1;
        appear[val]=i;
        a[pos]=val;
    }
    for(int num=1;num<=m+n;num++){
        if(appear[num]!=-1){
            cnt[num]+=(m+1-appear[num]);
        }
    }
    int res=0;
    for(int i=1;i<=m+n;i++){
        res+=get(cnt[i]);
    }
    cout<<res<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}