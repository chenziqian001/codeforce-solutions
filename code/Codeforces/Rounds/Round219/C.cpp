#include<bits/stdc++.h>
using namespace std;
#define int long long


struct node{
    int a,b,t;  
};



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    vector<node> fw(m);
    for(int i=0;i<m;i++) cin>>fw[i].a>>fw[i].b>>fw[i].t;
    vector<int> pdp(n+1);
    for(int j=1;j<=n;j++){
        pdp[j]=fw[0].b-abs(fw[0].a-j);
    }
    int pt=fw[0].t;
    

    for(int i=1;i<m;i++){
        int len=d*(fw[i].t-pt);
        deque<int> dq;
        int pos=fw[i].a;
        int val=fw[i].b;
        int k=1;
        vector<int> cdp(n+1);
        for(int j=1;j<=n;j++){
            int kmx=min(n,j+len);
            while(k<=kmx){
                while(!dq.empty() && pdp[dq.back()]<=pdp[k]){
                    dq.pop_back();
                }
                dq.push_back(k);
                k++;
            }
            int kmi=max(1LL,j-len);
            while(!dq.empty() && dq.front()<kmi){
                dq.pop_front();
            }
            int mx=pdp[dq.front()];
            cdp[j]=mx+val-abs(pos-j);
        }
        swap(pdp,cdp);
        pt=fw[i].t;
    }
    int res=-1e18;
    for(int i=1;i<=n;i++){
        res=max(res,pdp[i]);
    }
    cout<<res<<'\n';
    //system("pause");
    


}