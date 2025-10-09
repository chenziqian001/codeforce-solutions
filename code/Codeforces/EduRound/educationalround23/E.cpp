#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int h=31;
int son[N*30][2],cnt[N*30],id;

void init(){
    memset(son,0,sizeof(son));
    memset(cnt,0,sizeof(cnt));
    id=0;
}


void add(int x){
    int p=0;
    for(int k=h;k>=0;k--){
        int bit=(x>>k)&1;
        if(!son[p][bit]) son[p][bit]=++id;
        p=son[p][bit];
        cnt[p]++;
    }
}
void rem(int x){
    int p=0;
    for(int i=h;i>=0;i--){
        int bit=(x>>i)&1;
        int nx=son[p][bit];
        if(!nx) return;
        p=nx;
        cnt[nx]--;
    }
}


int get(int val,int l){
    int p=0;
    int res=0;
    for(int i=h;i>=0;i--){
        int bitl=(l>>i)&1;
        int bitval=(val>>i)&1;
        if(bitl){
            if(son[p][bitval]) res+=cnt[son[p][bitval]];
            if(!son[p][bitval^1]) return res;
            p=son[p][bitval^1];
        }
        else{
            if(!son[p][bitval]) return res;
            p=son[p][bitval];
        }
    }
    res+=cnt[p];
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int val;
            cin>>val;
            add(val);
        }
        else if(op==2){
            int val;
            cin>>val;
            rem(val);
        }
        else{
            int p,l;
            cin>>p>>l;
            cout<<get(p,l-1)<<'\n';
        }
    }
    
    return 0;
}