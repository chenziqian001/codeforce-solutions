#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int fw[N];

int n;
void add(int pos){
    for(int i=pos;i<=n;i+=(i&-i)){
        fw[i]++;
    }
}
int query(int pos){
    int res=0;
    for(int i=pos;i>0;i-=(i&-i)){
        res+=fw[i];
    }
    return res;
}
int a[N];
vector<int> g[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) g[min(i-1,a[i])].push_back(i);
    int res=0;
    for(int i=1;i<=n;i++){
        add(a[i]);
        for(int j=0;j<g[i].size();j++){
            res+=i-query(g[i][j]-1);
        }
    }
    cout<<res<<'\n';


    //system("pause");
}


