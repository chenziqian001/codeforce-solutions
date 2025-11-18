#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int h[N][23];
int l[N][23];
int a[N];
int n;

void init(){
    for(int i=0;i<n;i++){
        h[i][0]=a[i];
        l[i][0]=a[i];
    }

    for(int b=1;b<22;b++){
        for(int l=0;l+(1<<(b))-1<n;l++){
            h[l][b]=max(h[l][b-1],h[l+(1<<(b-1))][b-1]);
        }
    }
    for(int b=1;b<22;b++){
        for(int le=0;le+(1<<(b))-1<n;le++){
            l[le][b]=min(l[le][b-1],l[le+(1<<(b-1))][b-1]);
        }
    }
}


int geth(int l,int r){
    int k=__lg(r-l+1);
    return max(h[l][k],h[r-(1<<k)+1][k]);
}

int getl(int le,int r){
    int k=__lg(r-le+1);
    return min(l[le][k],l[r-(1<<k)+1][k]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    init();
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<geth(l,r)-getl(l,r)<<'\n';

    }
    //system("pause");
}