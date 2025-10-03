#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    vector<int> n2id(n);
    for(int i=0;i<n;i++){
        n2id[a[i]]=i;
    }
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--,k--;
        int lw=k;
        int bg=n-k-1;
        int pos=n2id[k];
        if(pos<l || pos>r){
            ans[i]=-1;
            continue;
        }
        int x=0,y=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos>mid){
                if(a[mid]>k){
                    x++;
                }
                else lw--;
                l=mid+1;
            }
            else if(pos<mid){
                if(a[mid]<k){
                    y++;
                }
                else bg--;
                r=mid-1;
            }
            else break;
        }
        if(x>lw || y>bg){
            ans[i]=-1;
            continue;
        }
        ans[i]=max(x,y)*2;
    }
    for(int res:ans){
        cout<<res<<" ";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}