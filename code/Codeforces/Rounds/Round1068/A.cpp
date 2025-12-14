#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int far=-1;

    int cnt=0;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='1'){
            far=max(far,i+k);
        }
        else{
            if(i>far){
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';

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

