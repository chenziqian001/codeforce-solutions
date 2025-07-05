#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    if((a>b+1)||(a%2==0&&a>b)){
        cout<<-1<<'\n';
    }
    else if((a%2==1)&&(a==(b+1))){
        cout<<y<<'\n';
    }
    else if(a==b){
        cout<<0<<'\n';
    }
    else{
        if(x<=y){
            cout<<(b-a)*x<<'\n';
        }
        else{
            long long res=0;
            if(a%2==0){
                res+=y;
                a+=1;
            }
            int n=b-a;
            if(n%2==0){
                res+=(n/2)*x+(n/2)*y;
            }
            else{
                res+=(n/2)*y+((n/2)+1)*x;
            }
            cout<<res<<'\n';

        }
    }


}


int main(){
    int t;
    cin>>t;
    while(t--) solve();

    system("pause");
    return 0;
}