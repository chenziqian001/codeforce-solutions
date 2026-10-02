#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<int> p(n);
    vector<vector<int>> a(n,vector<int>(n));
    if(s=="first"){
        for(int i=0;i<n;i++) cin>>p[i];
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                a[i][j]=p[j];
            }
        }
        for(int i=0;i<n;i++){
            swap(a[i][0],a[i][i]);
        }



        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        vector<int> ok(n+1);
        
        vector<int> res(n);
        for(int j=0;j<n;j++){
            vector<int> cnt(n+1);
            int mx=0;
            int num=-1;
            for(int i=0;i<n;i++){
                cnt[a[i][j]]++;
                if(cnt[a[i][j]]>mx){
                    mx=cnt[a[i][j]];
                    num=a[i][j];
                }
            }
            if(mx!=1){
                res[j]=num;
                ok[j]=1;
            }
        }
        int exa=-1;
        for(int i=1;i<=n;i++){
            if(!ok[i]){
                exa=i;
            }
        }

        for(int i=0;i<n;i++){
            if(res[i]==0){
                cout<<exa<<" ";
                continue;
            }
            cout<<res[i]<<" ";
        }
        cout<<'\n';
    }


    

}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
}