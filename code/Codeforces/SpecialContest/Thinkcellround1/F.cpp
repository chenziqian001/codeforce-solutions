#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1<<22;
bool s1[N],s2[N];
int res,k;


void ins1(int x){
    if(s1[x]) return;
    s1[x]=1;
    if(s2[x]) res=max(res,x);
    for(int i=0;i<k;i++) if((x>>i)&1) ins1(x^(1LL<<i));
}
void ins2(int x){
    if(s2[x]) return;
    s2[x]=1;
    if(s1[x]) res=max(res,x);
    for(int i=0;i<k;i++) if((x>>i)&1) ins2(x^(1LL<<i));
}



void solve(){
    int n,q;
    cin>>n>>q;
    int m=1;k=0;
    while(m<n) m<<=1,k++;
    m--;

    for(int i=0;i<=m;i++){
        s1[i]=s2[i]=0;
    }
    res=0;

    for(int i=0;i<q;i++){
        int e;
        cin>>e;
        int v=(e+res)%n;
        ins1(v);
        ins2(m^v);
        cout<<res<<(i==q-1?"":" ");
    }
    cout<<'\n';

    



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

