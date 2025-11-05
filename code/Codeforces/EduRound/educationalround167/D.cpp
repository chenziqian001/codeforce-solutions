#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+3;
const int inf=1e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(n);
    vector<int> best(N+1,inf);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x,-1};
    }
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        a[i].second=a[i].first-y;
    }
    for(int i=0;i<n;i++){
        best[a[i].first]=min(best[a[i].first],a[i].second);
    } 
    for(int i=1;i<=N;i++){
        best[i]=min(best[i],best[i-1]);
    }
    vector<int> ans(N+1);
    for(int i=1;i<=N;i++){
        if(i>=best[i]){
            ans[i]=ans[i-best[i]]+2;
        }
    }
    int res=0;
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        if(num>N){
            int k=(num-N+best[N]-1)/best[N];
            res+=2*k;
            int idx = num - k * best[N];
            if (idx < 0) idx = 0;
            res+=ans[idx];
        }
        else{
            res+=ans[num];
        }
    }
    cout<<res<<'\n';
    //system("pause");
}