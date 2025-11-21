#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<array<int,2>> v;
    int res=0;
    int cur=0;


    auto work=[&](int d){
        while(!v.empty() && cur<d){
            auto &[x,a]=v.back();
            if(x+k-1<cur){
                v.pop_back();
                continue;
            }

            if(a>=m){
                int r=min({cur+a/m-1,x+k-1,d-1});
                res+=r-cur+1;
                a-=m*(r-cur+1);
                cur=r+1;
                continue;
            }

            int need=m;
            while(!v.empty() && need>0){
                auto &[x,a]=v.back();
                if(cur>x+k-1){
                    v.pop_back();
                    continue;
                }

                if(a<=need){
                    need-=a;
                    v.pop_back();
                }
                else{
                    a-=need;
                    need=0;
                }
            }

            if(need==0){
                res++;
            }
            cur++;
        }
        cur=d;
    };
    


    for(int i=0;i<n;i++){
        int d,x;
        cin>>d>>x;
        work(d);
        v.push_back({d,x});
    }
    work(1e9);

    cout<<res<<'\n';



}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}