#include<bits/stdc++.h>
using namespace std;

/*
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
    vector<node> g;
    int res=0;
    for(int i=0;i<n;i++){
        int v=a[i];
        if(v==1){
            g.clear();
            res++;
            cout<<res<<" ";
            continue;
        }

        for(auto &p:g){
            p.v=gcd(p.v,v);
        }
        bool ok=false;
        for(auto &p:g){
            int pv=p.v;
            int l=i+1-pv;
            if(p.l<=l && l<=p.r){
                g.clear();
                res++;
                cout<<res<<" ";
                ok=true;
                break;
            }
        }
        if(ok) continue;

        g.push_back({v,i,i});
        int k=0;
        for(int j=1;j<g.size();j++){
            if(g[k].v!=g[j].v){
                g[++k]=g[j];
            }
            else g[k].r=g[j].r;
        }
        g.resize(k+1);
        cout<<res<<" ";
    }
    //system("pause");


}
*/
//以上为logtrick做法
//接下来尝试稀疏表+贪心+二分的做法
const int N=3e5+10;
int a[N];
int f[N][22];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int n;
void init(int n){
    for(int j=0;j<20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            if(!j) f[i][j]=a[i];
            else f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r){
    int len=r-l+1;
    int k=log(len)/log(2);
    return gcd(f[l][k],f[r-(1<<k)+1][k]);
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    init(n);
    int res=0;
    int pre=1;

    for(int i=1;i<=n;i++){
        if(a[i]==1){
            res++;
            pre=i+1;
            cout<<res<<" ";
            continue;
        }
        int l=pre,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(query(mid,i)>=i-mid+1){
                r=mid;
            }
            else l=mid+1;
        }
        if(query(l,i)==i-l+1){
            res++;
            pre=i+1;
        }
        cout<<res<<" ";
    }
    //system("pause");


}

//其实两个算法要解决的核心问题是一致的，一旦我们找到一个位置填了一个很大的质数后我们就可以不用管它的前缀了