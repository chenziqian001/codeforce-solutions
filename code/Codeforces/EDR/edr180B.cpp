#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=n;
    for(int i=0;i<n;i++){
        if(i>0&&(a[i]==a[i-1]||abs(a[i]-a[i-1])==1)){
            res=0;
            break;
        }
        if((i>0&&i<n-1)&&((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))){
            res=1;
        }
    }
    if(res==n) cout<<-1<<'\n';
    else cout<<res<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}