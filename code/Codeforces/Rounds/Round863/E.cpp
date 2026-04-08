#include<bits/stdc++.h>
using namespace std;



void solve(){
    long long k;
    cin>>k;
    string s;

    while(k){
        int x=k%9;
        s+='0'+(x<4?x:x+1);
        k/=9;
    }
    reverse(s.begin(),s.end());
    cout<<s<<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}