#include<bits/stdc++.h>
using namespace std;


const int N=1e7+10;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> lpf(N,0);
    for(int i=2;i<N;i++){
        if(lpf[i]==0){
            for(int j=i;j<N;j+=i) lpf[j]=i;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        y-=x;
        if(y==1){
            cout<<-1<<'\n';
            continue;
        }
        int tmp=y;
        int mini=y;
        while(tmp>1){
            int p=lpf[tmp];
            while(tmp%p==0) tmp/=p;
            if(x%p==0){
                mini=0;
                break;
            }
            mini=min(mini,p-x%p);
        }
        cout<<mini<<'\n';
    }
    return 0;
}


