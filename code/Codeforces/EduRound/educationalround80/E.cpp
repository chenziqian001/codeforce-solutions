#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> mn;
vector<int> mx;
vector<int> pos;
vector<int> tree;
void update(int p,int val){
    for(int i=p;i<tree.size();i+=i&-i){
        tree[i]+=val;
    }
}
int pre(int p){
    int res=0;
    for(int i=p;i>0;i-=i&-i){
        res+=tree[i];
    }
    return res;
}
int main(){
    cin>>n>>m;
    mn.resize(n);
    mx.resize(n);
    pos.resize(n);
    tree.resize(m+n+1);
    for(int i=0;i<n;i++){
        mn[i]=mx[i]=i;
        pos[i]=i+m;
        update(m+i+1,1);
    }
    for(int i=m-1;i>=0;i--){
        int f;
        cin>>f;
        f--;
        mn[f]=0;
        int old=pos[f];
        pos[f]=i;
        int pres=pre(old+1);
        mx[f]=max(mx[f],pres);
        update(old+1,-1);
        update(pos[f]+1,1);
    }
    for(int i=0;i<n;i++){
        cout<<mn[i]+1<<" "<<max(mx[i],pre(pos[i]+1))<<'\n';
    }
    system("pause");
    return 0;
}
