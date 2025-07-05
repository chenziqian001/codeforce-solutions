#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string col;
    cin>>col;
    set<int> st;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) st.insert(a[i]);
    int blue_block=0;
    bool secutive=false;
    for(int i=0;i<n;i++){
        if(col[i]=='B'){
            if(!secutive){
                blue_block++;
                secutive=true;
            }
        }
        else secutive=false;
    }
    if(blue_block<=k){
        cout<<0<<'\n';
        return;
    }
    vector<int> temp(st.begin(),st.end());
    int m=temp.size();
    int l=0,r=m-1;
    int ans=-1;
    auto check=[&](int numb){
        int seg=0;
        bool consecutive=false;
        for(int i=0;i<n;i++){
            if(a[i]<=numb) continue;
            if(col[i]=='B'){
                if(consecutive==false){
                    seg++;
                    consecutive=true;
                    if(seg>k) return false;
                }
            }
            else consecutive=false;
        }
        return true;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(temp[mid])){
            ans=temp[mid];
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    cout<<ans<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}