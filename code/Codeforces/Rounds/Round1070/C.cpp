#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    
    vector<int> odd;
    vector<int> even;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x&1) odd.push_back(x);
        else even.push_back(x);
    }
    sort(odd.rbegin(),odd.rend());
    sort(even.rbegin(),even.rend());


    if(odd.size()==0){
        for(int i=1;i<=n;i++){
            cout<<0<<" ";
        }
        cout<<'\n';
        return;
    }
    if(even.size()==0){
        for(int i=1;i<=n;i++){
            if(i%2==1) cout<<odd[0]<<" ";
            else cout<<0<<" ";
        }
        cout<<'\n';
        return;
    }

    cout<<odd[0]<<" ";
    int sum=0;
    for(int k=2;k<=1+(int)even.size();k++){
        sum+=even[k-2];
        cout<<odd[0]+sum<<" ";
    }
    for(int k=2+(int)even.size();k<=n;k++){
        if(k%2!=(int)even.size()%2) cout<<sum+odd[0]<<" ";
        else{
            if(k==n){
                cout<<0<<" ";
            }
            else{
                cout<<odd[0]+sum-even.back()<<" ";
            }
        }
    }
    cout<<'\n';
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