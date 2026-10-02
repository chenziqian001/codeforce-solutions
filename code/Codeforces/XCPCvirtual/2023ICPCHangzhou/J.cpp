#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=9e18;

int ask(int u ,int v){
    cout<<'?'<<" "<<u<<" "<<v<<endl;
    int res;
    cin>>res;
    return res;
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i+=2){
        int u=i,v=i+1;
        if(v>n){
            int rt=u;
            if(ask(rt,1) && ask(rt,2) && ask(rt,3)){
                cout<<'!'<<" "<<2<<endl;
                return;
            }
            else{
                cout<<'!'<<" "<<1<<endl;
                return;
            } 
        }
        else{
            if(ask(u,v)){
                vector<int> node;
                for(int j=1;j<=n;j++){
                    if(j!=u && j!=v) node.push_back(j);
                }
                if(ask(u,node[0])){
                    if(ask(u,node[1])){
                        cout<<'!'<<" "<<2<<endl;
                    }
                    else cout<<'!'<<" "<<1<<endl;
                }
                else{
                    if(ask(v,node[0]) && ask(v,node[1])){
                        cout<<'!'<<" "<<2<<endl;
                    }
                    else cout<<'!'<<" "<<1<<endl;
                }
                return;
            }
        }
    }
    cout<<'!'<<" "<<1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}




