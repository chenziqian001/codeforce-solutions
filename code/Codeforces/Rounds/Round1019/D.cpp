#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int pos=-1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        if(x==-1) pos=i;
    }
    vector<int> res(n);
    int l=1,r=n;
    for(int i=1;i<=20;i++){
        for(int j=0;j<pos;j++){
            if(a[j]!=i) continue;
            if(i%2==1) res[j]=r--;
            else res[j]=l++;
        }
        for(int k=n-1;k>pos;k--){
            if(a[k]!=i) continue;
            if(i%2==1) res[k]=r--;
            else res[k]=l++;
        }
    }
    res[pos]=l;
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<'\n';
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
