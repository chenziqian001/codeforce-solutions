#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    int sz=n*2+3;
    vector<int> hf(sz-2);
    int res=0;


    vector<array<int,26>> t(sz);
    vector<int> odd(sz);

    for(int r=0;r<m;r++){
        for(int i=0;i<sz;i++){
            t[i].fill(0);
            odd[i]=0;
        }
        odd[0]=2;
        odd[sz-1]=2;

        for(int l=r;l>=0;l--){
            for(int i=0;i<n;i++){
                int idx=i*2+2;
                int node=s[i][l]-'a';
                t[idx][node]++;

                if(t[idx][node]%2!=0) odd[idx]++;
                else odd[idx]--;
            }

            int bxm=0,bxr=0;
            for(int i=2;i<sz-2;i++){
                int hl=0;
                if(i<bxr){
                    hl=min(hf[bxm*2-i],bxr-i);
                }

                while(odd[i - hl] <= 1 && odd[i + hl] <= 1 && t[i - hl] == t[i + hl]){
                    hl++;
                    bxm=i;
                    bxr=i+hl;
                }

                hf[i]=hl;
                res+=hl/2;
            }
        }
    }


    cout<<res<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while (t--) solve();
    //system("pause");
    return 0;
}