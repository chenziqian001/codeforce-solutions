#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;

    vector<int> a(n+1);
    if(n%2==0){
        int num=1;
        for(int i=1;i<=n;i+=2){
            a[i]=a[i+1]=num++;
        } 
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    if(n<27){
        cout<<-1<<'\n';
        return;
    }
    a[1]=1;



    int num=2;
    for(int i=2;i<=8;i+=2){
        a[i]=a[i+1]=num++;
    }
    a[10]=a[26]=1;
    a[11]=a[27]=num++;
    for(int i=12;i<26;i+=2){
        a[i]=a[i+1]=num++;
    }
    for(int i=28;i<n;i+=2){
        a[i]=a[i+1]=num++;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';

    

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}