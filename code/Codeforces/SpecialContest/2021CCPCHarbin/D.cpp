#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
#define int long long
typedef __int128_t int128;



void solve(){
    string p,q;
    cin>>p>>q;
    int P=stoll(p),Q=stoll(q);
    int resx=P,resy=Q;
    int lp=p.size(),lq=q.size();

    int m=1<<lp;

    
    for(int st=1;st<m;st++){
        int x=0;
        int xl=0;
        vector<int> cnt(10);

        for(int i=0;i<lp;i++){
            if(st>>i&1){
                x=x*10+(p[i]-'0');
                xl++;
            }
            else{
                cnt[p[i]-'0']++;
            }
        }
        if(x==0 || x>=resx) continue;
        int128 x_128=x,Q_128=Q;
        if((x_128*Q_128)%P!=0) continue;
        int y=(int)((x_128*Q_128)/P);
        int yl=lq-(lp-xl);

        string Y=to_string(y);
        if(Y.length()>yl) continue;
        Y=string(yl-Y.length(),'0')+Y;


        int tmp=0;
        vector<int> cnt1(10);
        for(int i=0;i<lq;i++){
            if(tmp<yl && q[i]==Y[tmp]){
                tmp++;
            }
            else cnt1[q[i]-'0']++;
        }
        if(tmp==yl){
            bool ok=true;
            for(int i=0;i<10;i++){
                if(cnt[i]!=cnt1[i]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                resx=x;
                resy=y;
            }
        }
    }
    cout<<resx<<" "<<resy<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}



