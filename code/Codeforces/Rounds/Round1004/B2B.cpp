#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> cnt(n*2+10);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        cnt[x]++;
    }

    for(int i=0;i<=2*n;i++){
        if(cnt[i]==1){
            cout<<"NO"<<'\n';
            return;
        }        
        if(cnt[i]>2){
            cnt[i+1]+=cnt[i]-2;
        }    
    }

    cout<<"YES"<<'\n';
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
