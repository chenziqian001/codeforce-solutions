#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,m,k,b;
    cin>>n>>m>>k>>b;

    int res=0;
    int cnt=b;

    for(int i=0;i<n;i++){
        int cur=0;
        int reb=0;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            cur+=x;
            if(x<=0){
                reb+=(x+1);
            }
            else reb+=(x-1);
        }

        if(cur>=k) res++;
        else{
            if(reb>=k && cnt){
                res++;
                cnt--;
            }
        }
    }

    cout<<res<<'\n';


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