#include<bits/stdc++.h>
using namespace std;
int ask(string s){
    cout<<"1 "<<s<<endl;
    int res;
    cin>>res;
    return res;
}



void solve(){
    int n;
    cin>>n;
    int a=ask("1");
    int b=ask("10");
    int c=ask("11");
    if(a==b+c){
        cout<<"0 "<<n<<" "<<0<<endl;
    }
    else cout<<"0 "<<n<<" "<<1<<endl;
    cin>>n;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
