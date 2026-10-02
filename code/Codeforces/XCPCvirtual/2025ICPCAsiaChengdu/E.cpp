#include<bits/stdc++.h>
using namespace std;
const int M=998244353;

int n,q;
void solve(){
    cin>>n>>q;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        x--;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    
    

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pasue");
    return 0;
}
