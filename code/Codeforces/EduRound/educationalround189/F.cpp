#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void solve(){
    int n,l,k;
    cin>>n>>l>>k;
    string s;
    cin>>s;
    if(n<1LL*k*l){
        cout<<"NO\n";
        return;
    }
    vector<int> p1(n+1,1),p2(n+1,1),h1(n+1,0),h2(n+1,0);
    for(int i=0;i<n;i++){
        p1[i+1]=1LL*p1[i]*313%1000000007;
        p2[i+1]=1LL*p2[i]*317%1000000009;
        h1[i+1]=(1LL*h1[i]*313+s[i])%1000000007;
        h2[i+1]=(1LL*h2[i]*317+s[i])%1000000009;
    }
    auto gH=[&](int L,int R)->pair<int,int>{
        int len=R-L+1;
        int v1=(h1[R+1]-1LL*h1[L]*p1[len])%1000000007;
        if(v1<0) v1+=1000000007;
        int v2=(h2[R+1]-1LL*h2[L]*p2[len])%1000000009;
        if(v2<0) v2+=1000000009;
        return {v1,v2};
    };
    auto gLCP=[&](int i,int j,int mxL)->int{
        int low=1,high=mxL,ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(gH(i,i+mid-1)==gH(j,j+mid-1)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    };
    auto cmp=[&](int i,int l1,int j,int l2)->bool{
        int mn=min(l1,l2);
        int lcp=gLCP(i,j,mn);
        if(lcp==mn) return l1<l2;
        return s[i+lcp]<s[j+lcp];
    };
    int bId=-1,bLn=-1;
    for(int i=0;i<=n-l;i++){
        int c1=min(k-1,i/l);
        if(i>0&&c1==0) continue;
        int j=(c1==k-1)?n-1:n-1-(k-1-c1)*l;
        int ln=j-i+1;
        if(ln<l) continue;
        if(bId==-1||cmp(bId,bLn,i,ln)){
            bId=i;
            bLn=ln;
        }
    }
    cout<<"YES\n"<<s.substr(bId,bLn)<<"\n";
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int totalQueryNum;
    if(cin>>totalQueryNum){
        while(totalQueryNum--){
            solve();
        }
    }
    system("pause");
    return 0;
}