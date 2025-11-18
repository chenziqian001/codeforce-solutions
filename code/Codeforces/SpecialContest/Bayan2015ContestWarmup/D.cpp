#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,l,r;
};
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int q;
    cin>>q;
    map<int,long long> cnt;
    vector<node> g;
    for(int i=0;i<n;i++){
        int v=a[i];
        for(auto &p:g){
            p.v=gcd(p.v,v);
        }
        g.push_back({v,i,i});
        int k=0;
        for(int j=1;j<g.size();j++){
            if(g[k].v!=g[j].v){
                g[++k]=g[j];
            }
            else g[k].r=g[j].r;
        }
        g.resize(k+1);
        for(auto &p:g){
            cnt[p.v]+=p.r-p.l+1;
        }
    }    

    while(q--){
        int x;
        cin>>x;
        cout<<cnt[x]<<'\n';
    }
    //system("pause");

}