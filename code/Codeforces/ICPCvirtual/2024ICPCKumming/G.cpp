#include<bits/stdc++.h>
using namespace std;
int n;

void solve(){
    cin>>n;
    if(n==1 || n%4==0){
        cout<<"impossible"<<'\n';
        return;
    }
    int tot=1;
    cout<<1<<" "<<0<<" ";
    for(int i=2;i<n;i++){
        if((tot^i)==0){
            cout<<i+1<<" "<<i<<" ";
            tot^=i;
            tot^=i+1;
            i++;
        }
        else{
            cout<<i<<" ";
            tot^=i;
        }
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}