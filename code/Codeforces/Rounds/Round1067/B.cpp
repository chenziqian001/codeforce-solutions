#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(2*n+1);
    for(int i=0;i<2*n;i++){
        int x;
        cin>>x;
        a[x]++;
    }

    int c1=0;
    int c2=0;

    for(int i=1;i<=2*n;i++){
        if(a[i]==0) continue;
        if(a[i]%2==1){
            c1+=1;
        }
        else{
            c2+=1;
        }
    }


    if(c1==0 && c2%2!=n%2){
        cout<<(c2-1)*2<<'\n';
    }
    else cout<<c2*2+c1<<'\n';

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

