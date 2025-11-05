#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> res(2*n+1,-1);
    vector<int> a={1};
    vector<int> b;
    for(int i=2;i<=2*n;i++){
        cout<<"?"<<" ";
        cout<<(int)a.size()+1<<" ";
        for(int x:a){
            cout<<x<<" ";
        }
        cout<<i<<'\n';
        cout.flush();
        int r;
        cin>>r;
        if(r==0) a.push_back(i);
        else{
            res[i]=r;
            b.push_back(i);
        }
    }
    for(int i=1;i<=2*n;i++){
        if(res[i]==-1){
            cout<<'?'<<" ";
            cout<<(int)b.size()+1<<" ";
            for(int x:b){
                cout<<x<<" ";
            }
            cout<<i<<'\n';
            cout.flush();
            int r;
            cin>>r;
            res[i]=r;
        }
    }

    cout<<'!'<<" ";
    
    for(int x=1;x<=2*n;x++){
        cout<<res[x]<<" ";
    }
    cout<<'\n';
    cout.flush();



}


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}