#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n-2);
    for(int i=0;i<n-2;i++){
        cin>>a[i];
    }

    for(int i=0;i<n-2;i++){
        if(i!=0&&i!=n-3){
            if(a[i]==0&&(a[i-1]==1)&&(a[i+1]==1)){
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    cout<<"YES"<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}