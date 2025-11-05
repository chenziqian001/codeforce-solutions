#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,c,d;
    cin>>n>>c>>d;
    vector<pair<int,int>> coin;
    vector<pair<int,int>> dim;
    for(int i=0;i<n;i++){
        int buti,cost;
        char tp;
        cin>>buti>>cost>>tp;
        if(tp=='C') coin.emplace_back(buti,cost);
        else dim.emplace_back(buti,cost);
    } 
    int res=0;
    int tp1=0;
    int tp2=0;
    bool ok1=false,ok2=false;
    for(auto co:coin){
        if(co.second<=c){
            ok1=true;
            tp1=max(tp1,co.first);
        }
    }
    for(auto di:dim){
        if(di.second<=d){
            ok2=true;
            tp2=max(tp2,di.first);
        }
    }
    if(ok1 && ok2) res=tp1+tp2;
    sort(coin.begin(),coin.end(),[](auto a,auto b){
       return a.second<b.second; 
    });
    sort(dim.begin(),dim.end(),[](auto a,auto b){
       return a.second<b.second; 
    });
    auto get=[&](vector<pair<int,int>> &a,int have){
        int m=a.size();
        if(m<2) return;
        vector<int> pma(m);
        pma[0]=a[0].first;
        for(int i=1;i<m;i++){
            pma[i]=max(pma[i-1],a[i].first);
        }
        bool ok=false;
        int ans=0;
        for(int i=1;i<m;i++){
            if(a[i].second>have) break;
            int tmp=have-a[i].second;
            auto it = upper_bound(a.begin(), a.begin() + i,make_pair(INT_MAX, tmp),[](const auto& x, const auto& y){
                return x.second < y.second;
            });
            if(it!=a.begin()){
                ok=true;
                it--;
                int id=it-a.begin();
                ans=max(ans,a[i].first+pma[id]);
            }
        }
        if(ok){
            res=max(res,ans);
        }
    };
    get(coin,c);
    get(dim,d);
    cout<<res<<'\n';
    //system("pause");
}