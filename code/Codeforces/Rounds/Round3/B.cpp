#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;

int f(int a,int b){
    if(a>b) swap(a,b);
    if(a==0) return inf;
    if(a==1) return b-1;

    return b/a+f(b%a,a); 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int res=2*n;
    for(int i=1;i<=n;i++){
        res=min(res,f(i,n));
    }
    cout<<res<<'\n';
    return 0;
}




