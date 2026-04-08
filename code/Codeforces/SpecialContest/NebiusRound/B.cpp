#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=67667677;
const int N=3e5+10;
int cnt[N];

void init(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            cnt[j]++;
        }
    }    
};


void solve(){
    int x,y;
    cin>>x>>y;

    int n=x+y;
    vector<int> res(n);


    if(x==y){
        cout<<1<<'\n';
        for(int i=0;i<x;i++){
            res[i]=1;
            }
        for(int i=x;i<n;i++){
            res[i]=-1;
        }
    }
    else if(abs(x-y)==1){
        if(n%2==1){
            int a=x>y?1:-1;
            int b=a*-1;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    res[i]=a;
                }
                else{
                    res[i]=b;
                }
            }
            cout<<1<<'\n';
        }
        else{
            for(int i=0;i<x;i++){
                res[i]=1;
            }
            for(int i=x;i<n;i++){
                res[i]=-1;
            }
            
            int res=max(x,y)-min(x,y);
            cout<<cnt[res]<<'\n';

        }
    }
    else{
        
        for(int i=0;i<x;i++){
            res[i]=1;
        }
        for(int i=x;i<n;i++){
            res[i]=-1;
        }
        int res=max(x,y)-min(x,y);
        cout<<cnt[res]<<'\n';
        
    }

    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';



}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

