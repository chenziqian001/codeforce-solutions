#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=7e6;
int is_prime[N];
vector<int> primes;
vector<long long> ppf;
bool f(vector<long long>& pf,int md,int rt){
    if((pf[rt]-pf[md])>=(ppf[rt-md]-ppf[0])){
        return true;
    }
    else return false;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    vector<long long> pf(n+1);
    pf[0]=0;
    for(int i=1;i<=n;i++){
        pf[i]=pf[i-1]+a[i-1];
    }
    int l=0,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(f(pf,mid,n)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    cout<<ans<<'\n';
}
int main(){
    fill(is_prime,is_prime+N,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<N;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j=i*2;j<N;j+=i){
                is_prime[j]=false;
            }
        }
    }
    int s=primes.size();
    ppf.resize(s+1);
    ppf[0]=0;
    for(int i=1;i<=s;i++){
        ppf[i]=ppf[i-1]+primes[i-1];
    }
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}