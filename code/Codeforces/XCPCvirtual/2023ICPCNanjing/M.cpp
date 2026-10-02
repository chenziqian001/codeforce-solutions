#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+2);
    set<int> sL,sR;
    sL.insert(0);
    sR.insert(n+1);
    int sumf=0,sumg=0,suma=0,mxa=0;

    auto add=[&](int x,int v){
        suma+=v;
        auto itL=sL.find(x);
        if(itL!=sL.end()){
            int nxt=(next(itL)==sL.end()?n+1:*next(itL));
            sumf+=(nxt-x)*v;
        }else{
            itL=sL.lower_bound(x);
            int pre=*prev(itL);
            if(a[x]+v>a[pre]){
                int nxt=(itL==sL.end()?n+1:*itL);
                sumf+=(nxt-x)*(a[x]+v-a[pre]);
                sL.insert(x);
                itL=sL.find(x);
            }
        }
        if(itL!=sL.end()){
            auto nit=next(itL);
            while(nit!=sL.end()){
                int nxt=*nit;
                if(a[nxt]<=a[x]+v){
                    auto nnit=next(nit);
                    int nnxt=(nnit==sL.end()?n+1:*nnit);
                    sumf+=(nnxt-nxt)*(a[x]+v-a[nxt]);
                    sL.erase(nit);
                    nit=nnit;
                }else break;
            }
        }

        auto itR=sR.find(x);
        if(itR!=sR.end()){
            int pre=(itR==sR.begin()?0:*prev(itR));
            sumg+=(x-pre)*v;
        }else{
            itR=sR.upper_bound(x);
            int nxt=*itR;
            if(a[x]+v>a[nxt]){
                int pre=(itR==sR.begin()?0:*prev(itR));
                sumg+=(x-pre)*(a[x]+v-a[nxt]);
                sR.insert(x);
                itR=sR.find(x);
            }
        }
        if(itR!=sR.end()){
            while(itR!=sR.begin()){
                auto pit=prev(itR);
                int pre=*pit;
                if(a[pre]<=a[x]+v){
                    int ppre=(pit==sR.begin()?0:*prev(pit));
                    sumg+=(pre-ppre)*(a[x]+v-a[pre]);
                    sR.erase(pit);
                }else break;
            }
        }
        a[x]+=v;
        mxa=max(mxa,a[x]);
    };

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(i,x);
    }
    int q;
    cin>>q;
    while(q--){
        int x,v;
        cin>>x>>v;
        add(x,v);
        cout<<sumf+sumg-n*mxa-suma<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}