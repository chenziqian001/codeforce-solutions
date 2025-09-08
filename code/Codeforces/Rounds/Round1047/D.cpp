#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> cnt(n+1);
    vector<vector<int>> pos(n+1); 
    for(int i=0;i<n;i++){
        cnt[b[i]]++;
        pos[b[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]!=0){
            if(cnt[i]%i!=0){
                cout<<-1<<'\n';
                return;
            }
        }
    }
    int num=1;
    vector<int> a(n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<pos[i].size();j++){
            a[pos[i][j]]=num;
            if((j+1)%i==0) num++;
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<'\n';
    




}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}