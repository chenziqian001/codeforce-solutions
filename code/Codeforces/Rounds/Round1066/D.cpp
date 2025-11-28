#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> gp(n);

    sort(a.begin(),a.end());
    int ba=0;

    for(int i=0;i<n;i++){
        if(a[i]<l) gp[i]=1,ba++;
        else if(a[i]>r) gp[i]=-1,ba--;
    }

    for(int i=0,j=n-1;i<n && j>=0;i++,j--){
        if(gp[i]==0 && ba<0) gp[i]=1,ba++;
        if(gp[j]==0 && ba>0) gp[j]=-1,ba--;
        
    }

    int rem=0;

    for(int i=0;i<n;i++) rem+=(gp[i]==0);
    for(int i=0,j=1;i<n && j<=rem/2;i++){
        if(gp[i]==0) gp[i]=1,j++;
    }
    for(int i=n-1,j=1;i>=0 && j<=rem/2;i--){
        if(gp[i]==0) gp[i]=-1,j++;
    }

    int res1=0;
    int res2=0;

    for(int i=0;i<n;i++){
        if(gp[i]==1){
            res1+=l-a[i],res2+=r-a[i];
        }
        else if(gp[i]==-1){
            res1+=a[i]-l,res2+=a[i]-r;
        }
    }

    int res=min(res1,res2);
    cout<<res<<'\n';   

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






