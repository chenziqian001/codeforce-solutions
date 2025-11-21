#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int mxk=510;
int fw[N][mxk];
int h[N];
int n,k;
int mx;


void upd(int pos,int sel,int x){
    for(;pos<=mx+k;pos+=pos&-pos){
        for(int i=sel;i<=k+1;i+=i&-i){
            fw[pos][i]=max(fw[pos][i],x);
        }
    }
}


int query(int pos,int sel){
    int res=0;
    for(;pos;pos-=pos&-pos){
        for(int i=sel;i;i-=i&-i){
            res=max(res,fw[pos][i]);
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);    


    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        mx=max(mx,h[i]);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j--){
            int x=query(h[i]+j,j+1)+1;
            res=max(res,x);
            upd(h[i]+j,j+1,x);
        }
    }
    cout<<res<<'\n';
    //system("pause");
    return 0;
}