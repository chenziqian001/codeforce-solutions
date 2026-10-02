#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> a(20);
vector<vector<int>> op;
void move(int k,int s,int t){
    if(k<=0)return;
    int u=6-s-t;
    if(a[k-1]==0){
        move(k-1,s,u);
        op.push_back({k,s,t});
        move(k-1,u,t);
    }else{
        move(k-1-a[k-1],s,u);
        op.push_back({k,s,t});
        move(k-1-a[k-1],u,s);
        move(k-1,s,t);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]>i){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
    op.clear();
    move(n,1,3);
    cout<<op.size()<<"\n";
    for(auto& v:op) cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}