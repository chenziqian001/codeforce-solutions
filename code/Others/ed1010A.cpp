#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;
const int N=1e5+10;

long long inv2=500000004;


void solve(){
    int x;
    cin>>x;
    string s;
    cin>>s;
    long long hope=0;
    for(int i=x-1;i;i--){
        if(s[i]=='0'){
            hope=hope*inv2%M;
        }
        else{
            hope=inv2*(hope+1)%M;
        }
    }
    cout<<(x-1+hope)%M<<'\n';
}   

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}