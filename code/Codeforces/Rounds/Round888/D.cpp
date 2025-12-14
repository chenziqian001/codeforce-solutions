#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=1;i<n;i++){
        cin>>a[i];
    }

    vector<int> b;
    vector<int> vis(n+1);
    for(int i=1;i<n;i++){
        int val=a[i]-a[i-1];
        if(val>n || vis[val]) b.push_back(val);
        else vis[val]++;
    }
    if(b.size()>1){
        cout<<"NO"<<'\n';
        return;
    }


    int cnt=0;
    int x=-1,y=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            if(x==-1) x=i;
            else if(y==-1) y=i;
            else{
                cout<<"NO"<<'\n';
                return;
            }
        }
    }


    if(cnt>2){
        cout<<"NO"<<'\n';
        return;
    }
    if(cnt==1 && !b.empty()){
        if(vis[*b.begin()]){
            cout<<"NO"<<'\n';
            return;
        }
    }
    if(cnt==2){
        if((x+y)!=*b.begin()){
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

