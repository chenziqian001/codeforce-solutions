#include<bits/stdc++.h>
using namespace std;
int  n;

vector<int>  Z(string &s){
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
} 
int f(vector<int> &z,int len){
    int n=z.size();
    int cnt=1;
    for(int i=len;i<n;){
        if(z[i]>=len){
            cnt++;
            i+=len;
        }
        else i++;
    }
    return cnt;
}




void solve(){
    int l,r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    int n=s.size();
    int E=ceil(sqrt(n));
    vector<int> ans(n+1);
    vector<int> z=Z(s);
    for(int k=1;k<=E;k++){
        int L=0,R=n;
        int res=0;
        while(L<=R){
            int mid=(L+R)/2;
            if(mid==0) break;
            if(f(z,mid)>=k){
                L=mid+1;
                res=mid;
            }
            else R=mid-1;
        }
        ans[k]=res;
    }
    for(int len=1;len<=E;len++){
        int k=1;
        for(int i=len;i<n;){
            if(z[i]>=len){
                k++;
                i+=len;
            }
            else i++;
        }
        ans[k]=max(ans[k],len);
    }

    for(int i=n-1;i>=0;i--){
        ans[i]=max(ans[i+1],ans[i]);
    }
    for(int i=l;i<=r;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}