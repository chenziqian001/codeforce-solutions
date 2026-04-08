#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;

void solve(){
    int n;
    cin>>n;
    
    vector<int> a(n+1);
    a[0]=n;
    bool ok=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(1){
            if(a[i]>a[i-1]){
                ok=false;
            }
        }
    }
    if(!ok){
        cout<<"NO"<<'\n';
        return;
    }

    deque<int> dq;
    for(int i=0;i<a[n];i++) dq.push_back(i);

    vector<int> res(n);
    
    for(int i=n-1;i>=0;i--){
        if(a[i]==a[i+1]){
            if(!dq.empty()){
                int x=dq.front();
                dq.pop_front();
                res[i]=x;
            }
            else{
                cout<<"NO"<<'\n';
                return;
            }
        }
        else{
            res[i]=n+1;
            for(int j=a[i+1]+1;j<a[i];j++) dq.push_back(j);
        }
    }


    if(!dq.empty()){
        cout<<"NO"<<'\n';
        return;
    }
    else{
        cout<<"YES"<<'\n';
        for(int x:res){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
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
