#include<bits/stdc++.h>
using namespace std;
vector<int> p[2000005];
void solve(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p[x+1000000].push_back(i);
        ans=max(ans,(int)p[x+1000000].size());
    }
    if(k==0){
        cout<<ans<<'\n';
        return;
    }
    for(int val=0;val<=2000000;val++){
        if(p[val].empty())continue;
        int nval=val-k;
        if(nval<0||nval>2000000||p[nval].empty())continue;
        vector<int> &v=p[val];
        vector<int> &nv=p[nval];
        int i=0,j=0;
        int base=(int)v.size();
        int cur=0,mx=0;
        while(i<v.size()||j<nv.size()){
            while(i<v.size()&&j<nv.size()&&v[i]<nv[j]){
                cur=max(cur-1,-1);
                i++;
                mx=max(mx,cur);
            }
            while(i<v.size()&&j<nv.size()&&v[i]>nv[j]){
                cur=max(cur+1,1);
                j++;
                mx=max(mx,cur);
            }
            while(i==v.size()&&j<nv.size()){
                cur=max(cur+1,1);
                j++;
                mx=max(mx,cur);
            }
            while(j==nv.size()&&i<v.size()){
                cur=max(cur-1,-1);
                i++;
                mx=max(mx,cur);
            }
        }
        ans=max(ans,base+mx);
    } 
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    solve();
    //system("pause");
    return 0;
}