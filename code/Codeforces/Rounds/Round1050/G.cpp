#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<vector<int>> divisors(N);
void init(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> res(n);
    vector<int> cnt(n+1);
    int mx=0;
    vector<int> vis(n+1,0);
    vector<int> max_num;

    for(int i=0;i<n;i++){
        vector<int> nx;
        for(int d:divisors[a[i]]){   
            cnt[d]++;
            if(cnt[d]!=i+1) mx=max(mx,cnt[d]);
            else if(!vis[d]){
                max_num.push_back(d);
                vis[d]=1;
            }
        }
        for(int x:max_num){
            if(cnt[x]!=i+1){
                mx=max(mx,cnt[x]);
                vis[x]=0;
            }
            else nx.push_back(x);
        }
        max_num=nx;
        res[i]=mx;
    }

    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}