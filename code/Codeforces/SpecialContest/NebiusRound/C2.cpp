#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];

    vector<int> cnt(n+1,0);
    
    for(int c=0;c<k;c++){
        bool same=true;
        for(int i=c;i<n;i+=k){
            if(a[i]!=a[c]){
                same=false;
                break;
            }
        }
        if(!same){
            for(int i=c;i<n;i+=k){
                if(b[i]!=-1 && b[i]!=a[i]){
                    cout<<"NO"<<'\n';
                    return;
                }
            }
        }
        else{
            cnt[a[c]]++;
            int x=-1;
            for(int i=c;i<n;i+=k){
                if(b[i]!=-1){
                    if(x==-1) x=b[i];
                    else if(x!=b[i]){
                        cout<<"NO"<<'\n';
                        return;
                    }
                }
            }
            if(x!=-1) cnt[x]--;
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]<0){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}


