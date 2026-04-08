#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
 


int ask(int l,int r){
    int pos=-1;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>pos;
    return pos;
}

void solve(){
    int n;
    cin>>n;
    int lef=false;
    int pos=ask(1,n);
    if(pos!=1){
        if(ask(1,pos)==pos){
            lef=true;
        }
    }

    if(lef){
        int l=1,r=pos-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(ask(mid,pos)==pos) l=mid+1;
            else r=mid-1;
        }
        cout<<"! "<<r<<endl;
    }
    else{
        int l=pos+1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(ask(pos,mid)==pos) r=mid-1;
            else l=mid+1;
        }
        cout<<"! "<<l<<endl;
    }
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    solve();
    //system("pause");
    return 0;
}
