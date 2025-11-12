#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
vector<bool> is_prime;
vector<int> divi[N];
void init(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divi[j].push_back(i);
        }
    }
    
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> cnt(n+1);
    for(int x:a) cnt[x]++;
    
    vector<int> p(n+1);
    int ps=0;
    for(int i=n-1;i>=0;i--){
        if(is_prime[a[i]]){
            p[a[i]]++;
            ps++;
        }
    }//后缀质数

    int res=0;
    for(int i=0;i<n;i++){
        if(is_prime[a[i]]){
            ps--;
            p[a[i]]--;
            res+=ps-p[a[i]];
        }
    }// 计算纯质数对

    vector<int> tmp(n+1);

    for(int i=0;i<n;i++){
        if(is_prime[a[i]] || divi[a[i]].size()>3) continue;
        bool ok=true;
        for(int j=0;j<divi[a[i]].size()-1;j++){
            if(!is_prime[divi[a[i]][j]]){
                ok=false;
            }
        }
        if(!ok) continue;
        res++; //自己单独贡献
        res+=tmp[a[i]];//前面和自己一样的数字的贡献
        for(int j=0;j<divi[a[i]].size()-1;j++){
            res+=cnt[divi[a[i]][j]];
        }
        tmp[a[i]]++;
    }
    cout<<res<<'\n';


}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    is_prime.resize(N,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<N;i++){
        if(is_prime[i]){
            for(int j=i*2;j<N;j+=i){
                is_prime[j]=false;
            }
        }
    }
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}