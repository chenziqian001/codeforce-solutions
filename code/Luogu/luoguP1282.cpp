#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    
    int base=n*5;
    vector<int> f(base*2+1,inf);
    f[base]=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        int d=x-y;
        vector<int> nf(base*2+1,inf);

        for(int j=base-i*5;j<=base+i*5;j++){
            if(j<0 || j>=(int) f.size()) continue;
            if(j+d>=0 && j+d<(int)f.size()){
                nf[j+d]=min(nf[j+d],f[j]);
            }

            if(j-d>=0 && j-d<(int) f.size()){
                nf[j-d]=min(nf[j-d],f[j]+1);
            }
        }
        f=move(nf);
    }
    int res=inf;
    for(int i=0;i<=base;i++){
        res=min(f[base-i],f[base+i]);
        if(res<inf){
            break;
        }
    }
    cout<<res<<'\n';
    //system("pause");
    return 0;

}