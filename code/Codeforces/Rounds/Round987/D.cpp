#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int find(vector<int> &fa,int x){
    if(x!=fa[x]){
        fa[x]=find(fa,fa[x]);
    }
    return fa[x];
}
void merge(int x,int y,vector<int> &fa){
    int fx=find(fa,x);
    int fy=find(fa,y);
    if(fx==fy) return;
    if(a[fx]>=a[fy]){
        fa[fy]=fx;
    }
    else{
        fa[fx]=fy;
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pma(n+1);
    vector<int> smi(n+2);
    vector<int> fa(n+1);
    smi[n]=a[n];
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) pma[i]=max(pma[i-1],a[i]);
    for(int i=n-1;i>=1;i--) smi[i]=min(smi[i+1],a[i]);
    for(int i=1;i<n;i++){
        if(pma[i]>smi[i+1]){
            merge(i,i+1,fa);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<a[find(fa,i)]<<" ";
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