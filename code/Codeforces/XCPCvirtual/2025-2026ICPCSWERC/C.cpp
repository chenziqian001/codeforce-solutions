#include<bits/stdc++.h>
using namespace std;

int get(vector<int> &a,int b){
    for(int i=0;i<a.size();i++){
        if(a[i]==b) return i;
    }
    return -1;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int d=n*m/2;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<int> ans(n,-1),use(n);
    for(int i=0;i<n;i++){
        if(use[i]) continue;
        vector<int> cu,co,off(n,-1),q;
        off[i]=0;
        use[i]=1;
        q.push_back(i);
        int hd=0;
        while(hd<q.size()){
            int u=q[hd++];
            cu.push_back(u);
            co.push_back(off[u]);
            for(int j=0;j<m;j++){
                int x=v[u][j];
                for(int k=0;k<n;k++){
                    if(u==k) continue;
                    int id=get(v[k],x);
                    if(id!=-1 && off[k]==-1){
                        off[k]=((off[u]*m+j+d-id)%(n*m)+n*m)%(n*m)/m;
                        use[k]=1;
                        q.push_back(k);
                    }
                }
            }
        }
        for(int s=0;s<n;s++){
            bool ok=true;
            for(int k=0;k<cu.size();k++){
                if(ans[(s+co[k])%n]!=-1){
                    ok=false;
                    break;
                }
            }
            if(ok){
                for(int k=0;k<cu.size();k++){
                    ans[(s+co[k])%n]=cu[k];
                }
                break;
            }
        }
    }
    for(int i=0;i<d;i++){
        cout<<v[ans[i/m]][i%m]<<" ";
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