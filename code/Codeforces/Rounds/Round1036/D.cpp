#include<bits/stdc++.h>
using namespace std;
int n,k;
void solve(){
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(k==1){
        cout<<"YES"<<'\n';
        return;
    }
    vector<int> b;
    b=a;
    sort(b.begin(),b.end());
    int kth=b[k-2];
    vector<int> c;
    for(int num:a){
        if(num<=kth) c.push_back(num);
    }
    int m=c.size();
    int allow=m-(k-1);
    int l=0,r=m-1;
    bool ok=true;
    while(l<r){
        if(c[l]!=c[r]){
            if(allow==0){
                ok=false;
                break;
            }
            if(c[l]==kth){
                allow--;
                l++;
            }
            else if(c[r]==kth){
                allow--;
                r--;
            }
            else{
                ok=false;
                break;
            }
            continue;
        }
        l++;
        r--;
    }
    if(ok){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';

    return;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}