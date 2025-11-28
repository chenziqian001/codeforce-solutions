#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,l;
    cin>>n>>k>>l;
    vector<int> x0(k),x;

    for(int i=0;i<k;i++){
        cin>>x0[i];
    }

    sort(x0.begin(),x0.end());
    x0.erase(unique(x0.begin(),x0.end()),x0.end());
    k=x0.size();

    for(int i=0;i<k;i++){
        if(i==0 || x0[i-1]+1!=x0[i]){
            x.push_back(x0[i]-1);
        }
        if(i==k-1 || x0[i]!=x0[i+1]-1){
            x.push_back(x0[i]);
        }
    }

    k=x.size();
    sort(x.begin(),x.end());

    vector<int> a(l);
    for(int i=0;i<l;i++) cin>>a[i];


    vector<vector<int>> f(k);
    
    for(int i=0;i<k;i++){
        f[i].assign(n+1,-1);
        f[i][x[i]]=0;

        queue<int> q;
        q.push(x[i]);

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int len:a){
                if(u+len<=n && f[i][u+len]==-1){
                    f[i][u+len]=f[i][u]+1;
                    q.push(u+len);
                }
                if(u-len>=0 && f[i][u-len]==-1){
                    f[i][u-len]=f[i][u]+1;
                    q.push(u-len);
                }
            }

        }

    }


    vector<int> dp(1<<k,-1);
    dp[0]=0;

    for(int s=0;s+1<(1<<k);s++){
        if(dp[s]==-1) continue;

        int i;
        for(i=0;i<k;i++){
            if((s>>i&1)==0) break;
        }


        for(int j=i+1;j<k;j++){
            if((s>>j&1)==0 && f[i][x[j]]!=-1){
                int ns=s^(1<<i)^(1<<j);
                int cost=dp[s]+f[i][x[j]];
                if(dp[ns]==-1 || dp[ns]>cost){
                    dp[ns]=cost;
                }
            }
        }
    }


    cout<<dp[(1<<k)-1]<<'\n';

    //system("pause");
    return 0;    
}




