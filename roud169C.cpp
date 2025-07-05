#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),[](int a,int b){
        return a>b;
    });
    long long res=0;
    vector<int> diff(n+1);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        diff[l]++;
        diff[r+1]--;
    }    
    vector<int> cnt(n);
    long long num=0;
    for(int i=0;i<n;i++){
        num+=diff[i];
        cnt[i]=num;
    }
    sort(cnt.begin(),cnt.end(),[](int a,int b){
        return a>b;
    });
    for(int i=0;i<n;i++){
        res+=1LL*a[i]*cnt[i];
    }
    cout<<res;
    system("pause");
    return 0;
}