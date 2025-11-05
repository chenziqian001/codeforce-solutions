#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
void tran1(vector<string> &a){
    int n=a.size();
    int m=a[0].size();
    vector<string> res(m,string(n,'0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[j][i]=a[i][j];
        }
    }
    a=res;
}
void tran2(vector<vector<int>> &a){
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>> res(m,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[j][i]=a[i][j];
        }
    }
    a=res;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
   
    bool change=false;
    if(n>m){
        swap(n,m);
        tran1(a);
        change=true;
    }
    vector<vector<int>> res(n,vector<int>(m,inf));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vector<int> edge;
            for(int k=0;k<m;k++){
                if(a[i][k]=='0' || a[j][k]=='0') continue;
                edge.push_back(k);
            }
            for(int k=1;k<edge.size();k++){
                int st=edge[k-1],ed=edge[k];
                for(int p=st;p<=ed;p++){
                    res[j][p]=min(res[j][p],(ed-st+1)*(j-i+1));
                }
            }
        }
        for(int j=n-1;j>i;j--){
            for(int k=0;k<m;k++){
                res[j-1][k]=min(res[j-1][k],res[j][k]);
            }
        }
    }  
    if(change){
        swap(n,m);
        tran2(res);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(res[i][j]!=inf) cout<<res[i][j]<<" ";
            else cout<<0<<" ";
        }
        cout<<'\n';
    }
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