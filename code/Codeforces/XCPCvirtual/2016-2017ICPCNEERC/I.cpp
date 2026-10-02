#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{int a,b,id;};
int dp[3005][3005],ch[3005][3005];

void solve(){
    int n,p,s;
    cin>>n>>p>>s;
    vector<node> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i].a;
    for(int i=1;i<=n;i++)cin>>v[i].b;
    for(int i=1;i<=n;i++)v[i].id=i;
    sort(v.begin()+1,v.end(),[](node x,node y){return x.a-x.b>y.a-y.b;});
    for(int i=0;i<=n;i++){
        for(int j=0;j<=p+s;j++) dp[i][j]=-2e18;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i,p+s);j++){
            dp[i][j]=dp[i-1][j];
            ch[i][j]=0;
            if(j){
                int val=dp[i-1][j-1]+(j<=p?v[i].a:v[i].b);
                if(val>dp[i][j]){
                    dp[i][j]=val;
                    ch[i][j]=(j<=p?1:2);
                }
            }
        }
    }
    cout<<dp[n][p+s]<<'\n';
    vector<int> t1,t2;
    int cx=n,cy=p+s;
    while(cx && cy){
        if(ch[cx][cy]==1){
            t1.push_back(v[cx].id);
            cy--;
        }
        else if(ch[cx][cy]==2){
            t2.push_back(v[cx].id);
            cy--;
        }
        cx--;
    }
    for(int x:t1) cout<<x<<" ";
    cout<<'\n';
    for(int x:t2) cout<<x<<" ";
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}