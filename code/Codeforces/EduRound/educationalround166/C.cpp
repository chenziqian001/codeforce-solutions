#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;


void solve(){
    int n,m;
    cin>>n>>m;

    
    vector<int> a(n+m+1);
    vector<int> b(n+m+1);
    for(int i=0;i<n+m+1;i++) cin>>a[i];
    for(int i=0;i<n+m+1;i++) cin>>b[i];
    int k=n+m+1;

    vector<int> p(k);
    int bad=-1,tp=-1,ca=0,cb=0;
    for(int i=0;i<k;i++){
        p[i]=(i?p[i-1]:0)+max(a[i],b[i]);
        if(a[i]>b[i]) ca++;
        else cb++;
        if(ca==n+1 && bad==-1){
            bad=i;
            tp=1;
        }
        if(cb==m+1 && bad==-1){
            bad=i;
            tp=0;
        }
    }

    vector<int> sa(k+1);
    vector<int> sb(k+1);
    for(int i=k-1;i>=0;i--){
        sa[i]=sa[i+1]+a[i];
        sb[i]=sb[i+1]+b[i];
    }

    for(int i=0;i<k;i++){
        int res=0;
        int pre=bad?p[bad-1]:0;

        if(tp==1){
            if(i<bad && a[i]>b[i]){
                res=p[bad]-a[i]+sb[bad+1];
            }
            else{
                res=pre+sb[bad]-b[i];
            }
        }
        else{
            if(i<bad && b[i]>a[i]){
                res=p[bad]-b[i]+sa[bad+1];
            }
            else res=pre+sa[bad]-a[i];
        }

        cout<<res<<" ";
    }
    cout<<'\n';    
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