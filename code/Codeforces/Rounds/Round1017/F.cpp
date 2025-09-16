#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(m%k==0){
        int p=0;
        for(int i=0;i<n;i++){
            int cur=1+p;
            for(int j=0;j<m;j++){
                cout<<cur++<<" ";
                if(cur==k+1){
                    cur=1;
                }
            }
            cout<<'\n';
            if(p==0) p=1;
            else p=0;
        }
    }
    else{
        int cnt=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<cnt++<<" ";
                if(cnt==k+1) cnt=1;
            }
            cout<<'\n';
        }

    }

}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}

