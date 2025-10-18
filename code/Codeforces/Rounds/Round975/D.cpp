#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int dp[N*4][2][2][2];
int a[N];
void push_up(int id){
    for(int a=0;a<2;a++){
        for(int b=0;b<2;b++){
            for(int c=0;c+b<2;c++){
                for(int d=0;d<2;d++){
                    for(int e=0;e<2;e++){
                        for(int f=0;f+e<2;f++){
                            dp[id][a][d][e+f]=max(dp[id][a][d][e+f],dp[id*2][a][b][e]+dp[id*2+1][c][d][f]);
                        }
                    }
                }
            }
        }
    }
}

void build(int id,int l,int r){
    if(l==r){
        memset(dp[id],0,sizeof(dp[id]));
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    memset(dp[id],0,sizeof(dp[id]));
}
void update(int id,int l,int r,int p){
    if(l==r){
        dp[id][1][1][0]=1;
        dp[id][1][1][1]=a[p]+1;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid) update(id*2,l,mid,p);
    else update(id*2+1,mid+1,r,p);
    push_up(id);
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b;
    for(int i=0;i<n;i++) b.push_back(a[i]);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    int m=b.size();
    vector<vector<int>> pos(m);
    for(int i=0;i<n;i++){
        pos[lower_bound(b.begin(),b.end(),a[i])-b.begin()].push_back(i);
    }
    int res=0;
    build(1,0,n-1);
    for(int i=b.size()-1;i>=0;i--){
        for(int ps:pos[i]) update(1,0,n-1,ps);

        for(int a=0;a<2;a++){
            for(int g=0;g<2;g++){
                res=max(res,dp[1][a][g][1]+b[i]);
            }
        }
    }
    cout<<res<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}


