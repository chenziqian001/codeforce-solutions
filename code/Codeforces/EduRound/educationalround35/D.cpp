#include<bits/stdc++.h>
using namespace std;
 
 
struct BIT{
    vector<int> t;
    int n;
    BIT(int n):n(n),t(n+1,0) {}
    void add(int i,int val){
        for(;i<=n;i+=i&-i) t[i]+=val;
    }
    int sum(int i){
        int s=0;
        for(;i>=1;i-=i&-i) s+=t[i];
        return s;
    }
};
 
 
 
 
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int m;
    cin>>m;
    int inv=0;
    BIT bit(n);
    for(int i=0;i<n;i++){
        int greater=i-bit.sum(a[i]);
        inv^=(greater%2);
        bit.add(a[i],1);
    }
 
    while(m--){
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        inv^=((len*(len-1)/2)%2);
        if(inv==0){
            cout<<"even"<<'\n';
        }
        else{
            cout<<"odd"<<'\n';
        }
    }
 
    system("pause");
    return 0;
}