#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int lpf[N];
vector<int> group[N];
vector<int> primes;
void seive(){
    for(int i=2;i<=N;i++){
        if(lpf[i]==0){
            primes.push_back(i);
            for(int j=i;j<=N;j+=i){
                if(lpf[j]==0) lpf[j]=i;
            }
        }
    }
    for(int i=2;i<=N;i++){
        group[lpf[i]].push_back(i);
    }
   
}






void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> p(n);
    for(int i=2;i<=n;i++){
        if(!group[i].empty()){
            vector<int>& g=group[i];
            int m=g.size();
            for(int j=0;j<m;j++){
                int from=g[j];
                int to=g[(j+1)%m];
                if(to>n) to=g[0];
                p[from]=to;
            }
        }
    }
    vector<int> res(n+1);
    res[1]=1;
    for(int i=2;i<=n;i++){
        res[i]=p[i];
        cout<<res[i]<<(i==n?'\n':' ');        
    }
}
int main(){
    int t;
    cin>>t;
    seive();
    while(t--) solve();
    system("pause");
    return 0;
}