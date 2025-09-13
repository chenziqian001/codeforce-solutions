#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int l,r;
    int cnt;
    int mindis;
    int laz;  
};
int a[N];
node t[N*4];
vector<int> lucky;
void init(){
    for(int i=0;i<10000;i++){
        string s=to_string(i);
        bool ok=true;
        for(char c:s){
            if(c!='4' && c!='7'){
                ok=false;
                break;
            }
        }
        if(ok) lucky.push_back(i);
    }
}//初始化
int get_dis(int x){
    auto it=lower_bound(lucky.begin(),lucky.end(),x);
    int y=lucky[it-lucky.begin()];
    return y-x;

}// 算距离
void push_up(int i){
    t[i].cnt=t[i*2].cnt+t[i*2+1].cnt;
    t[i].mindis=min(t[i*2].mindis,t[i*2+1].mindis);
} //更新父亲节点

void apply(int i,int val){
    t[i].laz+=val;
    t[i].mindis-=val;
}
void push_down(int i){
    int laz=t[i].laz;
    if(!laz) return;
    apply(i*2,laz);
    apply(i*2+1,laz);
    t[i].laz=0;
}//更新懒标记
void setlef(int u){
    int i=t[u].l;
    t[u].mindis=get_dis(a[i]);
    t[u].cnt=(t[u].mindis==0);
}//初始化叶节点
void build(int u,int l,int r){
    t[u].l=l;
    t[u].r=r;
    if(l==r){
        setlef(u);
        return;
    }
    int m=(l+r)/2;
    build(u*2,l,m);
    build(u*2+1,m+1,r);
    push_up(u);
}//建树

void update(int i,int l,int r,int val){
    if(l<=t[i].l && r>=t[i].r && t[i].mindis>val){
        apply(i,val);
        return;
    } 
    if(t[i].l==t[i].r){
        a[t[i].l]+=val+t[i].laz;
        t[i].laz=0;
        setlef(i);
        return;
    }
    push_down(i);
    int m=(t[i].l+t[i].r)/2;
    if(l<=m) update(i*2,l,r,val);
    if(r>m) update(i*2+1,l,r,val);
    push_up(i);

}//更新操作
int query(int i,int l,int r){
    if(l<=t[i].l && r>=t[i].r){
        return t[i].cnt;
    }
    int m=(t[i].l+t[i].r)/2;
    int q1=0;
    int q2=0;
    if(l<=m) q1=query(i*2,l,r);
    if(r>m) q2=query(i*2+1,l,r);
    return q1+q2;
}
int main(){
    init();
    lucky.push_back(10000000);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);
    while(m--){
        string op;
        int l,r;
        cin>>op>>l>>r;
        l--,r--;
        if(op[0]=='c'){
            cout<<query(1,l,r)<<'\n';
        }
        else{
            int val;
            cin>>val;
            update(1,l,r,val);
        }
    }

    system("pause");
    return 0;
}