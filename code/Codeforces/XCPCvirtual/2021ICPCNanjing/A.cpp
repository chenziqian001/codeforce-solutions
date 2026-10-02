#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    char dx,dy;
    int px,py;
    if((a-1)>=n-a){
        dy='D';
        py=n;
    }
    else{
        dy='U';
        py=1;
    } 
    if((b-1)>=n-b){
        dx='R';
        px=n;
    }
    else{
        dx='L';
        px=1;
    } 
    
    for(int i=0;i<n-1;i++){
        cout<<dx;
    }
    for(int i=0;i<n-1;i++){
        cout<<dy;
    }
    if(px<b){
        for(int i=px;i<b;i++){
            cout<<'R';
        }
    }
    else{
        for(int i=px;i>b;i--){
            cout<<'L';
        }
    }
    if(py>a){
        for(int i=py;i>a;i--){
            cout<<'U';
        }
    }
    else{
        for(int i=py;i<a;i++){
            cout<<'D';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;

    while(t--) solve();
    //system("pause");
    return 0;
}

