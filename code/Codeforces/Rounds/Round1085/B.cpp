#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m,l;
    cin>>n>>m>>l;
    vector<int> a(l);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        a[x]=1;
    }

    vector<int> b(m);
    for(int i=0;i<l;i++){
        sort(b.rbegin(),b.rend());
        int pos=min(n,m-1);
        b[pos]++;
        if(a[i]){
            n--;
            *max_element(b.begin(),b.end())=0;
        }
    }
    cout<<*max_element(b.begin(),b.end())<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
