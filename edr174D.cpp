#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int a=0;
    while(a<n/2&&s[a]==s[n-a-1]){
        a++;
    }
    n-=a*2;
    s=s.substr(a,n);
    int ans=2e5;
    for(int t=0;t<2;t++){
        int l=0,r=n,res=-1;
        while(l<=r){
            int mid=(l+r)/2;
            vector<int> cnt(26);
            for(int i=0;i<mid;i++) cnt[s[i]-'a']++;
            bool ok=true;
            for(int i=0;i<min(n/2,n-mid);i++){
                char c=s[n-i-1];
                if(i<mid){
                    ok&=cnt[c-'a']>0;
                    cnt[c-'a']--;
                }
                else{
                    ok&=(s[i]==c);
                }
            }
            for(int n:cnt) ok&=(n%2==0);
            if(ok){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=min(ans,res);
        reverse(s.begin(),s.end());
    }
    cout<<ans<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}