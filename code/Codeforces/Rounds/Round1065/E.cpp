#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<int> res(n+1,0);
    vector<int> tmp;
    vector<bool> vis(n+1);
    for(int i=1;i<=n;i++){
        if(i%2==0) continue;
        if(i%3==0) continue;
        tmp.push_back(i);
    }
    int id=0;
    int sz=tmp.size();
    for(int i=1;i<=n;i+=3){
        if(id==sz) break;
        res[i]=tmp[id++];
        vis[tmp[id-1]]=true;
    }
    tmp.clear();
    id=0;

    for(int i=1;i<=n;i++){
        if(i%2==0){
            tmp.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            continue;
        }
        if(i%3==0){
            tmp.push_back(i);
        }
    }
    sz=tmp.size();
    for(int i=1;i<=n;i++){
        if(res[i]) continue;
        res[i]=tmp[id++];
        vis[tmp[id-1]]=true;
    }

    tmp.clear();
    for(int i=1;i<=n;i++){
        if(!vis[i]) tmp.push_back(i);
    }
    id=0;
    for(int i=1;i<=n;i++){
        if(res[i]) continue;
        else res[i]=tmp[id++];
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
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