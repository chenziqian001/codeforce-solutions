#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N=1000000+5;

const ull B=(ull) 1e8+7;

ull ha1[N],ha2[N],powB[N];

int n,m;

void init(){
    powB[0]=1;
    for(int i=1;i<=n;i++){
        powB[i]=powB[i-1]*B;
    }
}

ll counter(ull *h){
    sort(h+1,h+n+1);
    ll res=0;
    ll cnt=0;
    for(int i=2;i<=n;i++){
        if(h[i]==h[i-1]){
            cnt++;
            res+=cnt;
        }
        else cnt=0;
    }
    return res;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    init();

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ha1[u]+=powB[v];
        ha1[v]+=powB[u];
    }

    for(int i=1;i<=n;i++){
        ha2[i]=ha1[i]+powB[i];
    }



    ll res=counter(ha1)+counter(ha2);
    cout<<res<<'\n';
    //system("pause");
    return 0;

}
