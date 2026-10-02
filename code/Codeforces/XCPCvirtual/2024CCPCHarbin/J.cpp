#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;
void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> x(m+1),t(m+1);
    for(int i=1;i<=m;i++) cin>>x[i]>>t[i];

    vector<int> last(n+1,inf),nxt(m+1);
    for(int i=m;i>=1;i--){
        nxt[i]=last[t[i]];
        last[t[i]]=x[i];
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=1;i<=n;i++)q.push({last[i],a[i]});
    int cur=0;
    for(int i=1;i<=m;i++){
        int d=x[i]-cur;
        while(d>0&&!q.empty()){
            auto [nx,v]=q.top();
            q.pop();
            if(v<=d){
                d-=v;
            }else{
                q.push({nx,v-d});
                d=0;
            }
        }
        if(d>0){
            cout<<x[i]-d<<"\n";
            return;
        }
        while(!q.empty()&&q.top().first==x[i])q.pop();
        q.push({nxt[i],a[t[i]]});
        cur=x[i];
    }
    int ans=cur;
    while(!q.empty()){
        ans+=q.top().second;
        q.pop();
    }
    cout<<ans<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}