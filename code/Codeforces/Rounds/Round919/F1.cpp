#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m,q;
    cin>>n>>m>>q;

    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];

    int rt=n;
    int ct=-1;
    queue<int> qv;
    vector<int> d(n*m,-1);

    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(g[r][c]=='#'){
                if(r<rt){
                    rt=r;
                    ct=c;
                }
            }
            else if(g[r][c]=='v'){
                d[r*m+c]=0;
                qv.push(r*m+c);
            }
        }
    }

    int dr[]={-1,1,0,0};
    int dc[]={0,0,1,-1};

    while(!qv.empty()){
        int u=qv.front();
        qv.pop();
        int r=u/m,c=u%m;
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                int nu=nr*m+nc;
                if(d[nu]==-1){
                    d[nu]=d[u]+1;
                    qv.push(nu);
                }
            }
        }
    }



    for(int i=0;i<q;i++){
        int sx,sy;
        cin>>sx>>sy;
        sx--,sy--;

        auto check=[&](int D){
            if(d[sx*m+sy]<D) return false;
            vector<int> vis(n*m,0),val(n*m,0);
            queue<int> bq;
            int start=sx*m+sy;
            bq.push(start);
            vis[start]=1;
            
            while(!bq.empty()){
                int u=bq.front();
                bq.pop();
                int r=u/m,c=u%m;

                for(int j=0;j<4;j++){
                    int nr=r+dr[j],nc=c+dc[j];
                    if(nr>=0&&nr<n&&nc>=0&&nc<m&&g[nr][nc]!='#'){
                        int nu=nr*m+nc;
                        if(d[nu]<D) continue;
                        int w=0;
                        if(r<rt){
                            if(c==ct && nc==c+1) w=1;
                            else if(c==ct+1 && nc==ct) w=-1;
                        }

                        if(vis[nu]){
                            if(val[nu]!=val[u]+w) return true;

                        }
                        else{
                            vis[nu]=1;
                            val[nu]=val[u]+w;
                            bq.push(nu);
                        }
                    }

                }
            }
            return false;
        };

        int l=0,h=d[sx*m+sy],res=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid)){
                res=mid;
                l=mid+1;
            }   
            else{
                h=mid-1;
            } 
        }
        cout<<res<<'\n';
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
