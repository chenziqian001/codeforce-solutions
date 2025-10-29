#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int dg(int n){
    if(n==1){
        if(a[0]==0) return 0;
        else return 1;
    }
    bool ok=true;
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[i+n/2]){
            ok=false;
            break;
        }
    }
    if(ok){
        return dg(n/2);
    }
    else{
        for(int i=0;i<n/2;i++){
            a[i]^=a[i+n/2];
        }
        return n/2+dg(n/2);
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<dg(n)<<'\n';
    return 0;
}
