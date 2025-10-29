#include<bits/stdc++.h>
using namespace std;
vector<vector<double>> f;
const int N=5005;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> deg(n);
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        deg[u]++;
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end(), [](int x, int y) {
			return x > y;
		});
	}
    vector<double> p(n);
    p[n-1]=1.0;
    vector<vector<double>> v(n);
    for(int i=n-1;i>=0;i--){
        sort(v[i].begin(),v[i].end(),[](double x,double y){
            return x>y;
        });
        int len=v[i].size();
        for(int j=1;j<=len;j++){
            p[i]+=f[deg[i]][j]*v[i][j-1];
        }
        for(int pre:g[i]){
            v[pre].push_back(p[i]);
        }

    } 

    cout << fixed << setprecision(15) << p[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    f.resize(N,vector<double>(N));
    for(int i=1;i<5001;i++){
        f[i][1]=1.0/(double)i;
        if(i<2) continue;
        for(int j=2;j<=i;j++){
            f[i][j]=f[i-2][j-2]*(double)(j-2)/(double)i+f[i-2][j-1]*(double)(i-j)/(double)i;
        }
    }
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}