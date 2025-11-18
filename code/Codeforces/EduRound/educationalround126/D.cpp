#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];


    int sum=0;
    int cnt=0;
    int res=0;
    
    vector<int> ed(n);



    for(int i=n-1;i>=0;i--){
        sum-=cnt;
        b[i]-=sum;
        cnt-=ed[i];
        if(b[i]<=0) continue;

        int len=min(k,i+1);
        int need=(b[i]+len-1)/len;
        res+=need;
        sum+=need*len;
        cnt+=need;
        if(i-len>=0){
            ed[i-len]+=need;
        }
    }

    cout<<res<<'\n';
    //system("pause");
    return 0;
}


