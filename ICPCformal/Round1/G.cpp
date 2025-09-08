#include<bits/stdc++.h>
using namespace  std;
const int N=2e5+10;

int n,m;
int main(){
    cin>>n>>m;
    vector<int> cnt(n);
    int res=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a==b-1){
            if(cnt[a]==0){
                cnt[a]=1;
                res++;
            }
        }
    }
    if(res==n-1){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';
    system("pause");
    return 0;

    


}