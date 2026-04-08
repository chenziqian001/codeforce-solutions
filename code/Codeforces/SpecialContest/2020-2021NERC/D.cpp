#include<bits/stdc++.h>
using namespace std;
#define int long long


struct node{
    int i,j;
    bool use;
};


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>1){
            a.push_back(x);
        }
    }
    n=a.size();
    if(n==0){
        if(d==1){
            cout<<1<<'\n';
            cout<<1<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
        //system("pause");
        return 0;
    }


    vector<vector<double>> dp(n,vector<double>(10,-1.0));
    vector<vector<node>> fa(n,vector<node>(10,{0,0,false}));
    for(int i=0;i<n;i++){
        int x=a[i];
        double lg=log(x);
        int lst=x%10;

        if(i==0){
            dp[i][lst]=lg;
            fa[i][lst]={i,lst,true};
            continue;
        }

        dp[i]=dp[i-1];
        if(dp[i][lst]<0 || dp[i][lst]<lg){
            dp[i][lst]=lg;
            fa[i][lst]={i,lst,true};
        }
        for(int j=0;j<10;j++){
            if(dp[i-1][j]<0) continue;
            int nx=(j*lst)%10;
            if(dp[i-1][j]+lg>dp[i][nx]){
                dp[i][nx]=dp[i-1][j]+lg;
                fa[i][nx]={i-1,j,true};
            }
        }
    }

    vector<int> res;
    int i=n-1,j=d;
    while(1){
        node f=fa[i][j];
        if(!f.use){
            if(i==0){
                cout<<-1<<'\n';
                //system("pause");
                return 0;
            }
            i--;
            continue;
        }
        res.push_back(a[i]);
        if(f.i==i) break;
        i=f.i;
        j=f.j;
    }

    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x<<" ";
    }
    cout<<'\n';

    //system("pause");
    return 0;
}