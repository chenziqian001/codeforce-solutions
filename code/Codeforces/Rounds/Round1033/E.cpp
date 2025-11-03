#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;
const int N=2e5+10;

int n,k;
bool check(int v,vector<int> a){
    int more=0;
    int less=0;
    for(int i=0;i<n;i++){
        less+=max(0LL,v-a[i]);
        more+=max(0LL,a[i]-(v+k));
    }
    return more>=less;
    
}//我们要找到一个尽可能的大的合法的v，因为只有当所有车道的车的数量尽可能的均衡才可以使得我们的策略是最优的
int acsum(int x){
    return x*(x+1)/2;
}

void solve(){
    cin>>n>>k;
    int l=inf,r=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        l=min(l,a[i]);r=max(r,a[i]);
    }
    sort(a.begin(),a.end());
    int v=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,a)){
            v=mid;
            l=mid+1;
        }
        else r=mid-1;
    }//我们的最优的策略其实到这里已经出来了，但是很遗憾答案要求我们返回的是最小愤怒值

    int def=0,defs=0;
    int exc=0,excs=0;
    int more=0;
    for(int i=0;i<n;i++){
        def+=max(0LL,v-a[i]);//缺口车数
        defs+=v>a[i];        //有缺口的车道数
        exc+=max(0LL,a[i]-(v+k));//超出v+k的车数
        excs+=(a[i]>v+k);//超出v+k的车道数
        more+=max(0LL,a[i]-(v+k+1));
    }

    int res=0;

    if(more>=def){ //如果我的那些超多的车道可以完美补齐缺失车数
        int fix=more-def;
        res+=fix*acsum(v+1)+(defs-fix)*acsum(v);//可以思考一下为什么这里会有v+1出现，并且为什么它们的总数不可能达到defs
        res+=excs*acsum(v+k+1);
        res+=more*k;
    }
    else{
        int fix=exc-def;
        res+=defs*acsum(v);
        res+=fix*acsum(v+k+1)+(excs-fix)*acsum(v+k);
        res+=def*k;
    }
    for(int i=defs;i+excs<n;i++){
        res+=acsum(a[i]);
    }//这些车道的数量在v--v+k之间，我们之前没有处理它们
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}