#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;

    int c4=0;
    int c8=0;
    for(int i=0;i<n;i++){
        if(s[i]=='4') c4++;
        if(s[i]=='8') c8++;
    }

    if(abs(x)>n || abs(y)>n){
        cout<<"NO"<<'\n';
        return;
    }

    int safe=n-c4;
    x=abs(x);
    y=abs(y);

    if(x<=safe){
        cout<<"YES"<<'\n';
    }
    else{
        int more=x-safe;
        if(y>n-more){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
    }
}


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}