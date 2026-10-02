#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    vector<int> tmp;
    for(int i=0;i<n;i++){
        if(i && a[i]-a[i-1]>k){
            int m=tmp.size();
            if(tmp[0]==tmp[m-1]){
                if(tmp.size()%2==0){
                    cout<<"YES"<<'\n';
                    return;
                }  
            }
            else{
                cout<<"YES"<<'\n';
                return;
            }

           
            tmp.clear();
        }
        tmp.push_back(a[i]);
    }
    int m=tmp.size();
    if(tmp[0]==tmp[m-1]){
        if(tmp.size()%2==0){
            cout<<"YES"<<'\n';
            return;
        }
    }
    else{
        cout<<"YES"<<'\n';
        return;
    }
  

    cout<<"NO"<<'\n';

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