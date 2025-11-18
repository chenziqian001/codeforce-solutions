#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;


    int sum=0;
    int a=0;
    int b=0;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='B'){
            a++;
            if((i+1)%2==0){
                b++;
            }
        }
        else{
            sum+=a;
        }
    }
    int d=abs(a/2-b);
    cout<<d+(sum-d)/2<<'\n';





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


