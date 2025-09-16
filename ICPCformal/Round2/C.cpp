#include<bits/stdc++.h>
using namespace std;

void solve(){
    int s;
    cin>>s;
    vector<int> f(8);
    for(int i=1;i<=7;i++){
        cin>>f[i];
    }
    int ave=s/3;

    int l=0,r=ave;
    int res=0;
    auto check=[&](int a){
        for(int g=1;g<=7;g++){
            int sum=0;
            for(int s=1;s<=7;s++){
                if(g&s){
                    sum+=f[s];
                }
            }
            if(a*__builtin_popcount(g)>sum){
                return false;
            }
        }
        return true;

    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<res<<'\n';
    
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}