#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    vector<vector<int>> cnt(n,vector<int>(26));
    for(int i=0;i<n;i++){
        for(char c:s[i]){
            cnt[i][c-'a']++;
        }
    }
    int N=1<<n;


    vector<int> f(N);
    vector<int> mn(26,INT_MAX);
    for(int i=1;i<N;i++){
        for(int j=0;j<26;j++) mn[j]=INT_MAX;
        
        for(int st=i;st;st=st&(st-1)){
            int id=__builtin_ctz(st);
            for(int j=0;j<26;j++){
                mn[j]=min(mn[j],cnt[id][j]);
            }
        }

        int k=__builtin_popcount(i);
        int res=((k%2)?1:-1)+mod;
        for(int j=0;j<26;j++){
            if(mn[j]!=INT_MAX){
                res=res*(mn[j]+1)%mod;
            }
        }

        f[i]=res;
    } 


    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++){
            if(j>>i&1){
                f[j]=(f[j]+f[j^(1<<i)])%mod;
            }
        }
    }

    int ans=0;
    
    for(int i=1;i<N;i++){
        int k=__builtin_popcount(i);
        int sum=0;
        for(int j=i;j;j=j&(j-1)){
            int id=__builtin_ctz(j);
            sum+=id;
        }
        sum+=k;

        ans^=k*sum*f[i];
    }
    cout<<ans<<'\n';
    //system("pause");
}