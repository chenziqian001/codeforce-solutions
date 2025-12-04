#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
bool vis[N];
int n;

int get(int k){
    memset(vis,0,sizeof(vis));
    int res=1;
    int st=0;

    int tmp=0;
    
    for(int i=0;i<n;i++){
        if(!vis[a[i]]){
            tmp++;
            vis[a[i]]=1;
        }
        if(tmp>k){
            res++;
            tmp=1;
            
            for(int j=st;j<i;j++){
                vis[a[j]]=0;
            }
            st=i;
        }
    }

    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sz=sqrt(n);
    for(int i=1;i<=n;i++){
        if(i<=sz){
            cout<<get(i)<<" ";
        }
        else{
            int res=get(i);
            int l=i,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                if(get(mid)<res) r=mid-1;
                else l=mid+1;
            }
            for(int st=i;st<=l-1;st++){
                cout<<res<<" ";
            }
            i=l-1;
        }
    }

    //system("pause");
    return 0;
}