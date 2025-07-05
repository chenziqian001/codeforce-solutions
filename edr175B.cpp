#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
    long long n,x,k;
    cin>>n>>x>>k;
    string cm;
    cin>>cm;
    bool touch=false;
    long long res=0;
    for(char c:cm){
        if(c=='L')x-=1;
        else x+=1;
        k--;
        if(x==0){
            res++;
            touch=true;
            break;
        }
        if(k==0) break;
    }
    if(!touch){
        cout<<res<<'\n';
        return;
    }
    else{
        long long T=0;
        bool restrain=false;
        for(char c:cm){
            if(c=='L') x-=1;
            else x+=1;
            T++;
            k--;
            if(x==0){
                res++;
                restrain=true;
                break;
            }
            if(k==0) break;
        }
        if(!restrain){
            cout<<res<<'\n';
            return;
        }
        else cout<<res+(k/T)<<'\n';
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}