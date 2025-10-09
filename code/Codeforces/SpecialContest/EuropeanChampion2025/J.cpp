#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cntw=0;
    int cntr=0;
    for(int i=0;i<n;i++) if(s[i]=='W') cntw++;
    for(int i=2*n-1;i>=n;i--) if(s[i]=='R') cntr++;
    if(cntw%2 || cntr%2 || cntw!=cntr){
        cout<<"NO"<<'\n';
        return;
    }
    int h=cntw/2;
    int ok=1;
    for(int i=0;i<h;i++){
        if(s[i]!='W'){
            ok=0;
            break;
        }
    }
    if(!ok){
        cout<<"NO"<<'\n';
        return;
    }
    ok=1;
    for(int i=2*n-1;i>=2*n-h;i--){
        if(s[i]!='R'){
            ok=0;
            break;
        }
    }
    if(!ok){
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



