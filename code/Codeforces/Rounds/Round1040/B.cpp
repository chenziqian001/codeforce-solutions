#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(a[i]==1) cnt1++;
        if(a[i]==2) cnt2++;
    }
    if(s<sum){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    int cnt0=n-cnt1-cnt2;
    if(s==sum+1){
        for(int i=0;i<cnt0;i++){
            cout<<0<<" ";
        }
        int prev=1;
        while(cnt1!=0 && cnt2!=0){
            if(prev==1){
                cout<<2<<" ";
                cnt2--;
                prev=2;
            }
            else {
                cout<<1<<" ";
                prev=1;
                cnt1--;
            }
        }
        int remain=0;
        if(cnt1!=0){
            remain=1;
        }
        else remain=2;
        for(int i=0;i<max(cnt1,cnt2);i++){
            cout<<remain<<'\n';
        }
        cout<<'\n';
        
    }
    else{
        cout<<-1<<'\n';
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}