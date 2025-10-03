#include<bits/stdc++.h>
#include<cassert>
using namespace std;
#define int long long
const int inf=1e18;

struct node{
    int val,l,r;
};
struct tree{
    int n,sz=0;
    vector<int> vec;
    tree(int n):n(n),vec(n+1,0) {}
    void add(int i,int val){
        sz+=val;//这个很重要，可以实时维护sum
        for(;i<=n;i+=i&-i) vec[i]+=val;
    }//更新操作

    int kth(int x){
        int pos=0;
        for(int k=18;k>=0;k--){
            if((pos|(1<<k))<=n && vec[pos|(1<<k)]<x){
                x-=vec[pos|=(1<<k)];
            }
        }
        return pos+1;
    }

    void qmid(int &lef,int &rig){
        lef=kth((sz+1)/2);
        rig=kth(sz/2+1);
    }

    void __clear(){
        fill(vec.begin(),vec.end(),0);
        sz=0;
    }
};//树装数组结构体

int find(vector<int> &p,int x){
    if(x!=p[x]) p[x]=find(p,p[x]);
    return p[x];
} //并查集基操

node get_max(vector<int> &a,int n,int k){
    int l=1,r=n;
    int res=0,resl=0,resr=0;
    while(l<=r){
        int mid=(l+r)/2;
        vector<int> pre(n+1);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+(mid<=a[i]?1:-1);
        }
        int mn=inf,ll,rr;
        int ok=0;
        for(int i=k;i<=n;i++){
            if(pre[i-k]<mn) ll=i-k+1;
            mn=min(mn,pre[i-k]);
            if(pre[i]-mn>=0){
                ok=1;
                rr=i;
                break;
            }
        }
        if(ok){
            res=mid;
            l=mid+1;
            resl=ll;
            resr=rr;
        }
        else r=mid-1;
    } 
    return {res,resl,resr};
}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<node> res(n+1);//结果数组

    vector<int> p(n+2); 
    for(int i=1;i<=n+1;i++) p[i]=i; //并查集及其数组的更新

    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i]; //输入
    
    
    node ed=get_max(a,n,k); //这是max_median
    for(int i=1;i<=n;i++) a[i]=n-a[i]+1;//对数组进行翻转
    node st=get_max(a,n,k); //这是min_median
    st.val=n-st.val+1; //不要忘了将你求到的min_median反转回来
    for(int i=1;i<=n;i++) a[i]=n-a[i]+1; //将整个数组翻转回来
    

    tree t(n);//初始化树状数组

    int stl=st.l;
    int str=st.r;
    int edl=ed.l;
    int edr=ed.r;

    auto f=[&](){
        int lef=0,rig=0;//lef是合法median下标的下界，vice versa
        assert(t.sz>0);
        t.qmid(lef,rig);//这里回去看tree结构体，这个函数利用求第k个函数更新上下界
        while((lef=find(p,lef))<=rig){//利用并查集防止重复更新
            res[lef]={0,stl,str};
            p[lef]=lef+1; //被用过了就指向下一个位置，可以压缩路径，不然你每次都要从左到右检查复杂度爆炸
        }
    };//这个函数用来标记所有在合法median区间里面的所有median

    t.__clear(); //保险起见，清理一遍

    for(int i=st.l;i<=st.r;i++){
        t.add(a[i],1);
    }//别忘了初始化数组

    f();
    while (stl > edl) t.add(a[--stl],1), f();
    while (str < edr) t.add(a[++str],1), f();
    while (stl < edl) t.add(a[stl++], -1), f();
    while (str > edr) t.add(a[str--], -1), f();
    f(); //这几个循环的目的是不断调整初始区间使得最后和max_median的区间一致
    //这里要补充的一点是由中值定理可以知道，任何值x只要满足min_median<=x<=max_median,
    //它也一定是合法的median
    //因为你在调整区间的时候，一定是一个连贯的过程，median不会突然增加或者减少好几个数字，一定是缓慢变化的


    cout<<ed.val-st.val+1<<'\n';
    for(int i=st.val;i<=ed.val;i++){
        cout<<i<<" "<<res[i].l<<" "<<res[i].r<<'\n';
    }//输出结果


}
signed main(){
    int tt;
    cin>>tt;
    while(tt--) solve();
    system("pause");
    return 0;
}


