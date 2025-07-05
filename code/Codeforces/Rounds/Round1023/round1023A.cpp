#include<iostream>
#include<vector>
using namespace std;




void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mini=100000;
    int maxi=-1;
    for(int i=0;i<n;i++){
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);
    }
    if(mini==maxi){
        cout<<"No"<<'\n';
        return;
    }
    cout<<"Yes"<<'\n';
    for(int i=0;i<n;i++){
        cout<<1+(a[i]==maxi)<<" ";
        
    }
    cout<<'\n';
    return;

    



}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}