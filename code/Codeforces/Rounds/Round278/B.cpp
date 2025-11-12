#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,s,l;
    cin>>n>>s>>l;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> dp(n+1,inf);
    dp[0]=0;
    deque<int> qmx,qmi,qdp;
    for(int i=0,j=0;i<n;i++){
        while(!qmx.empty() && a[i]>a[qmx.back()]){
            qmx.pop_back();
        }
        qmx.push_back(i);
        while(!qmi.empty() && a[i]<a[qmi.back()]){
            qmi.pop_back();
        }
        qmi.push_back(i);
        if(i+1-l>=j){
            while(!qdp.empty() && dp[i+1-l]<dp[qdp.back()]){
                qdp.pop_back();
            }
            qdp.push_back(i+1-l);
        }
        while(a[qmx.front()]-a[qmi.front()]>s){
            if(qmx.front()==j){
                qmx.pop_front();
            }
            if(qmi.front()==j){
                qmi.pop_front();
            }
            if(!qdp.empty() && qdp.front()==j){
                qdp.pop_front();
            }
            j++;
        }
        if(!qdp.empty()){
            dp[i+1]=dp[qdp.front()]+1;
        }
        else dp[i+1]=n+1;
        
    }
    int res=dp[n];
    if(res>n) cout<<-1<<'\n';
    else cout<<res<<'\n';
    //system("pause");
    return 0;
}