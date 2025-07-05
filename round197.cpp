#include<bits/stdc++.h>
using namespace std;
const  int N=270000;
long long a[N];
int update(int p,int v,int status){
    if(p==1){
        a[p]=v;
        return v;
    }
    int np=p/2;
    int near=p%2==0?p+1:p-1;
    int nv=status?v|a[near]:v^a[near];
    a[p]=v;
    return update(np,nv,1-status);
}

int main(){
    int n,m;
    cin>>n>>m;
    int len=1<<n;
    int size=2*len-1;
    int start=size-len+1;
    for(int i=start;i<=size;i++) cin>>a[i];    
    int cur_len=len;
    int cur_start=start;
    int status=1;
    while(cur_start>1){
        for(int i=cur_start;i<cur_start+cur_len;i+=2){
            a[i/2]=status?a[i]|a[i+1]:a[i]^a[i+1];
        }
        cur_len/=2;
        cur_start/=2;
        status=1-status;
    }
    for(int i=0;i<m;i++){
        int p,b;
        cin>>p>>b;
        p--;
        update(p+start,b,1);
        cout<<a[1]<<'\n';
    }
    system("pause");
    return 0;

}