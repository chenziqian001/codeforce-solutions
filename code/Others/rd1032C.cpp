#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(m));
    int maxi=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            g[i][j]=x;
            if(x>maxi){
                maxi=x;
                cnt=1;
            }
            else if(x==maxi){
                cnt++;
            }
        }
    }
    vector<int> row(n);
    vector<int> col(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==maxi){
                row[i]++;
                col[j]++;
            }
        }
    }
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]+col[j]-(g[i][j]==maxi)==cnt){
                flag=1;
                break;
            }
        }
    }
    cout<<maxi-flag<<'\n';
    return;
    
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}