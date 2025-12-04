/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;



int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,mod-2);
}

int get_det(vector<vector<int>> a){
    int n=a.size();
    int det=1;

    for(int i=0;i<n;i++){
        int pivot=i;
        while(pivot<n && a[pivot][i]==0) pivot++;
        if(pivot==n) return 0;
        if(pivot!=i){
            swap(a[pivot],a[i]);
            det=(mod-det)%mod;
        }

        det=det*a[i][i]%mod;
        int iv=inv(a[i][i]);


        for(int r=i+1;r<n;r++){
            if(a[r][i]==0) continue;
            int fac=a[r][i]*iv%mod;
            for(int c=i;c<n;c++){
                a[r][c]=(a[r][c]-fac*a[i][c]+mod)%mod;
            }
        }

    }
    return det%mod;
}

signed main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        if(u==n-1) u=0;
        else if(u==0) u=n-1;
        if(v==n-1) v=0;
        else if(v==0) v=n-1;

        if(t==1){
            a[u][v]=(a[u][v]-w+mod)%mod;
            a[v][v]=(a[v][v]+w)%mod;
        }
        else{
            a[u][v]=(a[u][v]-w+mod)%mod;
            a[v][u]=(a[v][u]-w+mod)%mod;
            a[u][u]=(a[u][u]+w)%mod;
            a[v][v]=(a[v][v]+w)%mod;
        }
        
    }
    if (n > 1LL) {
        for(int i=0;i<n;i++) a[i].pop_back();
        a.pop_back();
    } else {
        cout << 1LL << '\n';
        return 0;
    }

    cout<<get_det(a)<<'\n';
    system("pause");
}
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,mod-2);
}

int get_det(vector<vector<int>> a){
    int n=a.size();
    int det=1;

    for(int i=0;i<n;i++){
        int pivot=i;
        while(pivot<n && a[pivot][i]==0) pivot++;
        if(pivot==n) return 0;
        if(pivot!=i){
            swap(a[pivot],a[i]);
            det=(mod-det)%mod; 
        }

        det=det*a[i][i]%mod;
        int iv=inv(a[i][i]);

        for(int r=i+1;r<n;r++){
            if(a[r][i]==0) continue;
            int fac=a[r][i]*iv%mod;
            for(int c=i;c<n;c++){
                a[r][c]=(a[r][c] - fac * a[i][c] % mod + mod) % mod;
            }
        }
    }
    return det;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        
        if(u==n-1) u=0;
        else if(u==0) u=n-1;
        if(v==n-1) v=0;
        else if(v==0) v=n-1;

        if(t==1){
            a[u][v]=(a[u][v]-w+mod)%mod;
            a[v][v]=(a[v][v]+w)%mod;
        }
        else{
            // 无向图
            a[u][v]=(a[u][v]-w+mod)%mod;
            a[v][u]=(a[v][u]-w+mod)%mod;
            a[u][u]=(a[u][u]+w)%mod;
            a[v][v]=(a[v][v]+w)%mod;
        }
    }
    
    if (n > 1) {
        for(int i=0;i<n;i++) a[i].pop_back();
        a.pop_back();
    } else {
        cout << 1 % mod << '\n';
        return 0;
    }

    cout<<get_det(a)<<'\n';
    //system("pause");
    return 0;
}