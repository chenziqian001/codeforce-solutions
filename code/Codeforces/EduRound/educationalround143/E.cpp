#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    auto work=[&](){
        vector<int> res(n);
        vector<int> h=a;
        vector<int> s(n+1);
        for(int i=1;i<=n;i++) s[i]+=s[i-1]+h[i-1];
        for(int i=0;i<n;i++) h[i]-=i;
        vector<int> s1(n+1);
        for(int i=1;i<=n;i++) s1[i]+=s1[i-1]+h[i-1];
        deque<int> dq;
        int p=0;
        int sum=0;
        for(int i=0;i<n;i++){
            while(!dq.empty() && h[i]<h[dq.back()]){
                int x=dq.back();
                dq.pop_back();
                if(dq.empty()){
                    sum-=h[x]*(x-p+1);
                }
                else sum-=h[x]*(x-dq.back());
            }
            if(dq.empty()){
                sum+=h[i]*(i-p+1);
            }
            else sum+=h[i]*(i-dq.back());
            dq.push_back(i);
            while(h[dq[0]]+p<0){
                p++;
                sum-=h[dq[0]];
                if(dq[0]<p){
                    dq.pop_front();
                }
            }
            res[i]=(s1[i+1]-s1[p])-sum+s[p];
        }
        return res;
    };
    vector<int> l=work();
    reverse(a.begin(),a.end());
    vector<int> r=work();
    reverse(r.begin(),r.end());
    reverse(a.begin(),a.end());
    int res=inf;
    for(int i=0;i<n;i++){
        res=min(res,l[i]+a[i]+r[i]);
    }
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



