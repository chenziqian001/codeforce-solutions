#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    a[n-1]--;
    sort(a.begin(),a.end());
    if(a[n-1]-a[0]>k||sum%2==0){
        cout<<"Jerry"<<'\n';
        return;
    }
    cout<<"Tom"<<'\n';
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