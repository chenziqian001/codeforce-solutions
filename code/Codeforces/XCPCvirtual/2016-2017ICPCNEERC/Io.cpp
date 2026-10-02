#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{int a,b,id;};
int dp[3005][3005],ch[3005][3005];

void solve(){
    int n,p,s;
    cin>>n>>p>>s;
    vector<node> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i].a;
    for(int i=1;i<=n;i++)cin>>v[i].b;
    for(int i=1;i<=n;i++)v[i].id=i;
    sort(v.begin()+1,v.end(),[](node x,node y){return x.a-x.b>y.a-y.b;});
    vector<int> pre(n+2),suf(n+2);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1,q2;
    int sum=0;
    for(int i=1;i<=n;i++){
        q1.push({v[i].a,v[i].id});
        sum+=v[i].a;
        if(q1.size()>p){
            sum-=q1.top().first;
            q1.pop();
        }
        pre[i]=sum;
    }
    sum=0;
    for(int i=n;i>=1;i--){
        q2.push({v[i].b,v[i].id});
        sum+=v[i].b;
        if(q2.size()>s){sum-=q2.top().first;q2.pop();}
        suf[i]=sum;
    }
    int res=-1,pos=0;
    for(int i=p;i<=n-s;i++){
        if(pre[i]+suf[i+1]>res){
            res=pre[i]+suf[i+1];
            pos=i;
        }
    }
    cout<<res<<'\n';
    while(q1.size())q1.pop();
    while(q2.size())q2.pop();
    for(int i=1;i<=pos;i++){
        q1.push({v[i].a,v[i].id});
        if(q1.size()>p)q1.pop();
    }
    for(int i=n;i>pos;i--){
        q2.push({v[i].b,v[i].id});
        if(q2.size()>s)q2.pop();
    }
    vector<int> t1,t2;
    while(q1.size()){t1.push_back(q1.top().second);q1.pop();}
    while(q2.size()){t2.push_back(q2.top().second);q2.pop();}
    for(int x:t1) cout<<x<<" ";
    cout<<'\n';
    for(int x:t2) cout<<x<<" ";
    cout<<'\n';

    

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}