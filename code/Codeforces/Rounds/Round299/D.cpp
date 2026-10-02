#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;



int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;string p;cin>>p;

    int len = p.size();
    vector<int> pi(len+1);
    for(int i=1,j=0;i<len;i++){
        while(j && p[i]!=p[j]) j=pi[j];
        if(p[i] == p[j]) j++;
        pi[i+1] = j;
    }

    vector<bool> isb(len+1);
    int cur=pi[len];
    while(cur){
        isb[cur]=1;cur=pi[cur];
    }
    
    vector<int> y(m);


    int lst=0;
    int free=0;
    for(int i=0;i<m;i++){
        cin>>y[i];
        if(i>0){
            int d=y[i]-y[i-1];
            if(d<len && !isb[len-d]){
                cout<<0<<'\n';
                return 0;
            }
        }
        int st=y[i],ed=y[i]+len-1;
        if(st>lst){
            free+=(st-lst-1);
        }  
        lst=max(lst,ed);
    }
    free+=(n-lst);
    cout<<qp(26,free)<<'\n';
    //system("pause");
}