#include<bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int> fa;
    dsu(int n){
        fa.resize(n);
        for(int i=0;i<n;i++) fa[i]=i;
    }

    int find(int x){
        if(x!=fa[x]){
            fa[x]=find(fa[x]);
        }
        return fa[x];
    }


    void merge(int x,int y){
        int fx=fa[x];
        int fy=fa[y];
        
        if(fx!=fy){
            fa[fx]=fy;
        }
    }

};

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i],a[i]--;
    sort(a.begin(),a.end());

    int l=0,r=n+1;
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        vector<int> cnt(4*n+10);
        dsu d(n*4+10);

        for(int i=n-1;i>=0;i--){
            int val=a[i];
            int to=d.find(val);
            if(to-val<=mid){
                cnt[to]+=1;
                d.merge(to,to+1);
            }
            else cnt[val+mid]+=1;
        
        }

        if(*max_element(cnt.begin(),cnt.end())>k){
            l=mid+1;
        }
        else{
            r=mid-1;
            res=mid;
        }
    }

    cout<<res<<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}