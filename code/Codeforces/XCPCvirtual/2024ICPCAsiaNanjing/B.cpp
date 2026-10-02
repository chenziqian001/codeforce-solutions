#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[i]!='2') s[i]='0'+('1'-s[i]);
        }
        if(s[i]=='0') cnt0++;
        else if(s[i]=='1') cnt1++;
        else cnt2++;
    }
    int diff=abs(cnt0-cnt1);
    if(cnt2<=diff){
        cout<<diff-cnt2<<'\n';
    } 
    else cout<<(cnt2-diff)%2<<'\n';

}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}