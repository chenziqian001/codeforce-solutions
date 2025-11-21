#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int cnt[N];
int pre[N];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    for(int i=1;i<N;i++){
        pre[i]=pre[i-1]+cnt[i];
    }

    int res=0;
    vector<int> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    
    for(int x:b){
        int sum=0;
        int p=1;
        int c=x;
        while(c<N){
            sum+=(pre[c-1]-pre[p-1])*(c-x);
            p=c;
            c+=x;
        }
        sum+=(pre[N-1]-pre[p-1])*(c-x);


        res=max(res,sum);
    }


    cout<<res<<'\n';
    //system("pause");
    return 0;
}