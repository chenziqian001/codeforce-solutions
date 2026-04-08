#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int fw[N],val[N];
int n,m,q;


set<int> st; 

void add(int i,int v){
    for(;i<N;i+=i&-i) fw[i]+=v;
}

int query(int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=fw[i];
    return s;
}

int get(int l,int r){
    return val[l]*(r-l-1)*(r-l)/2;
}

int pre(int x){
    if(x==0) return 0;
    auto it=prev(st.upper_bound(x));
    int l=*it;
    if(l==x){
        return query(x-1);
    }
    int r=*next(it);
    return query(l-1)+val[l]*(2*r-l-x-1)*(x-l)/2;
}



void solve(){
    cin>>n>>m>>q;

    
    vector<int> x(m);
    for(int i=0;i<m;i++) cin>>x[i];
    for(int i=0;i<m;i++) cin>>val[x[i]];
    for(int i=0;i<m;i++) st.insert(x[i]);


    for(auto it=st.begin();next(it)!=st.end();it++){
        add(*it,get(*it,*next(it)));
    }

    while(q--){
        int tp;
        cin>>tp;
        if(tp==1){
            int x,v;
            cin>>x>>v;
            auto itr=st.upper_bound(x);
            auto itl=prev(itr);
            int l=*itl,r=*itr;
            
            add(l,-get(l,r));
            val[x]=v;
            st.insert(x);
            add(l,get(l,x));
            add(x,get(x,r));
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<pre(r)-pre(l-1)<<'\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();

    //system("pause");
    return 0;
}
