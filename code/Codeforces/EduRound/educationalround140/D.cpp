#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') cnt++;
    }
    for(int i=(1<<cnt);i<=(1<<n)-(1<<(n-cnt))+1;i++){
        cout<<i<<" ";
    }
    cout<<'\n';

    return 0;
}


