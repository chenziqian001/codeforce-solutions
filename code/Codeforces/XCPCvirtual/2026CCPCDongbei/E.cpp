#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    if(!(cin>>n))return;
    mt19937 rng(1337);
    vector<int> p(131072);
    iota(p.begin(),p.end(),0);
    shuffle(p.begin(),p.end(),rng);
    
    vector<int> v(17),sz(17);
    for(int b=0;b<17;b++){
        vector<int> q;
        for(int i=1;i<=n;i++)if(p[i]>>b&1)q.push_back(i);
        sz[b]=q.size();
        if(q.empty())continue;
        cout<<"? "<<sz[b];
        for(int x:q)cout<<" "<<x;
        cout<<endl;
        cin>>v[b];
    }
    
    int res=-1,f=-1;
    for(int b=0;b<17;b++)if(v[b]>0){f=b;break;}
    if(f==-1)res=1;
    else{
        int V=4*v[f];
        int lim=round(sqrt(V));
        for(int x=lim;x>=1;x--){
            if(V%x==0){
                int y=V/x;
                if((x+y)%2==0){
                    int s=(x+y)/2;
                    if(s>n)continue;
                    bool ok=1;
                    for(int b=0;b<17;b++){
                        int d=s*s-4*v[b];
                        if(d<0){ok=0;break;}
                        int r=round(sqrt(d));
                        if(r*r!=d){ok=0;break;}
                        int x1=(s-r)/2,x2=(s+r)/2;
                        bool c1=(x1>=0&&x1<=sz[b]&&s-x1>=0&&s-x1<=n-sz[b]);
                        bool c2=(x2>=0&&x2<=sz[b]&&s-x2>=0&&s-x2<=n-sz[b]);
                        if(!c1&&!c2){ok=0;break;}
                    }
                    if(ok){res=s;break;}
                }
            }
        }
    }
    cout<<"! "<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}