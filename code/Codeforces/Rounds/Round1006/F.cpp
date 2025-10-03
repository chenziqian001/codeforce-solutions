#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int cnt[N];
void init(){
    cnt[0]=cnt[1]=0;
    for(int i=2;i<N;i++){
        int x=i;
        cnt[i]=cnt[i-1];
        while(x%2==0){
            cnt[i]++;
            x>>=1;
        }
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    n--;
    for(int i=0;i<=n;i++){
        cout<<k*(cnt[n]==(cnt[i]+cnt[n-i]))<<" ";
    }
    cout<<'\n';
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}







