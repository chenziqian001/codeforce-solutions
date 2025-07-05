#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a[N];
int tt[N];
int tree[N];
int cnt[N];
int rm[N];
void add(int pos,int val){
    for(int i=pos;i<N;i+=i&(-i)){
        tree[i]+=val;
    }
}
int get(int p){
    int res=0;
    for(int i=p;i>=1;i-=i&(-i)){
        res+=tree[i];
    }
    return res;
}





int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x,tt[i]=x;
    }
    sort(tt,tt+n);
    int nn=unique(tt,tt+n)-tt;
    for(int i=0;i<n;i++){
        a[i]=lower_bound(tt,tt+nn,a[i])-tt;
    }
    for(int i=n-1;i>=0;i--){
        cnt[a[i]]++;
        add(cnt[a[i]]+1,1);
        rm[i]=cnt[a[i]];
    }
    long long res=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        add(rm[i]+1,-1);
        cnt[a[i]]++;
        res+=get(cnt[a[i]]);
        
    }
    cout<<res<<'\n';
    system("pause");
    return 0;

}