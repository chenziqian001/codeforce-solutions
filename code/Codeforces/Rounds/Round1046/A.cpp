#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int g1=c-a;
    int g2=d-b;
    if(max(a,b)>=3 && max(a,b)>(2*(min(a,b)+1))){
        cout<<"NO"<<'\n';
        return;
    }
    if(max(g1,g2)>=3 && max(g1,g2)>(2*(min(g1,g2)+1))){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}