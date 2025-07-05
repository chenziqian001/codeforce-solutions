#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> mini(n);
    vector<int> maxi(n);
    int mi=a[0];
    int ma=a[n-1];
    for(int i=0;i<n;i++){
        mi=min(mi,a[i]);
        mini[i]=mi;
    }
    for(int j=n-1;j>=0;j--){
        ma=max(ma,a[j]);
        maxi[j]=ma;
    }
    string s;
    for(int i=0;i<n;i++){
        if((a[i]==mini[i])||(a[i]==maxi[i])) s+="1";
        else s+="0";
    }
    cout<<s<<'\n';


}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
