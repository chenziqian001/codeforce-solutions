#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long k;
    cin>>k;
    long long res=0;
    long long base=9;
    long long len=1;
    while(k>len*base){
        k-=len*base;
        len++;
        base*=10;
    }
    string s=to_string(base/9+(k-1)/len);
    for(int i=0;i<(k-1)%len+1;i++){
        res+=s[i]-'0';
    }
    long long pre=0;
    for(int i=0;i<s.size();i++){
        int numb=s[i]-'0';
        if(numb){
            res+=numb*(len-1)*base/2+numb*(2*pre+numb-1)/2*base/9;
        }
        base/=10;
        len--;
        pre+=numb;
    }
    cout<<res<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
