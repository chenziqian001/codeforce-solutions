#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;


struct info{
    int x,d,id;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> px(n),py(n),ys;
    for(int i=0;i<n;i++){
        cin>>px[i]>>py[i];
        ys.push_back(py[i]-k+1);
        ys.push_back(py[i]+1);
    }  

    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    int m=ys.size();

    vector<info> e;
    for(int i=0;i<n;i++){
        e.push_back({px[i]-k+1,+1,i});
        e.push_back({px[i]+1,-1,i});
    }

    sort(e.begin(),e.end(),[](const info& a, const info& b){
        return a.x<b.x;
    });

    vector<int> cnt(m),last(m),res(n+1);
    for(auto i:e){
        int lo=py[i.id]-k+1,hi=py[i.id]+1;
        int l = lower_bound(ys.begin(), ys.end(), lo) - ys.begin();
        int r = lower_bound(ys.begin(), ys.end(), hi) - ys.begin();
        for (int j = l; j < r; j++) {
            int c = cnt[j];
            if (c > 0) {
                res[c] +=(i.x - last[j]) * (ys[j + 1] - ys[j]);
            }
            cnt[j]+=i.d;
            last[j]=i.x;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout<<res[i]<<" ";
    }
    cout<<'\n';
    //system("pause");
}

