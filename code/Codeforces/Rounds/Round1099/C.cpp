#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
void solve(){
    int n;cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int c=0;
        while(1){
            v.push_back({x,c});
            if(x==1){
                v.push_back({2,c+1});
                break;
            }
            if(x==2){
                v.push_back({1,c+1});
                break;
            }
            if(x%2)x++;
            else x/=2;
            c++;
        }
    }
    sort(v.begin(),v.end());
    int res=inf;
    for(int i=0;i<v.size();){
        int j=i,s=0;
        while(j<v.size()&&v[j].first==v[i].first){
            s+=v[j].second;
            j++;
        }
        if(j-i==n)res=min(res,s);
        i=j;
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    
    while(t--)solve();
    //system("pause");
    return 0;
}

