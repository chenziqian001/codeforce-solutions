#include<iostream>
#include<vector>
#include<set>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<bool> seen(n,false);
    if(a[n-1]==b[n-1]){
        cout<<n<<'\n';
        return;
    }
    for(int i=n-2;i>=0;i--){
        if(i+2<n){
            seen[a[i+2]]=true;
            seen[b[i+2]]=true;
        }
        if(a[i]==b[i]||a[i]==a[i+1]||b[i]==b[i+1]){
            cout<<i+1<<'\n';
            return;
        }
        if(i+2<n&&(seen[a[i]]||seen[b[i]])){
            cout<<i+1<<'\n';
            return;
        }
    }
    cout<<0<<'\n';
    
}



int main(){
    int t;
    cin>>t;

    while(t--) solve();
    system("pause");
    return 0;
}