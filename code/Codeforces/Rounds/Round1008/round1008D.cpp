#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct rule{
    char op1;
    int x;
    char op2;
    int y;
};

void solve(){
    int n;
    cin>>n;
    vector<rule> g(n);
    for(int i=0;i<n;i++){
        char a;
        int x;
        char b;
        int y;
        cin>>a>>x>>b>>y;
        g[i]={a,x,b,y};
    }
    ll l=1,r=1;

    for(int i=0;i<n;i++){
        ll ex=0;
        if(g[i].op1=='+') ex+=g[i].x;
        else ex+=g[i].x*l-l;
        if(g[i].op2=='+') ex+=g[i].y;
        else ex+=g[i].y*r-r;
        bool left=true;
        for(int j=i+1;j<n;j++){
            if(g[j].op1=='x'){
                if(g[j].op2=='x'){
                    if(g[j].x==g[j].y) continue;
                    else if(g[j].x<g[j].y){
                        left=false;
                    }
                    
                }
                break;

            }
            else{
                if(g[j].op2=='x'){
                    left=false;
                    break;
                }
            }
        }
        if(left) l+=ex;
        else r+=ex;
    }
    cout<<l+r<<'\n';

}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
