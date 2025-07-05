#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


void solve(){
    int n;
    long long k;
    cin>>n>>k;
    long long ans=0;
    long long cnt[60] {};
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;

        ans+=__builtin_popcountll(a);
        for(int j=0;j<60;j++){
            if (((~a) >> j) & 1){
                cnt[j]++;
            }
        }

    }

    for(int i=0;i<60;i++){
        long long t=min(cnt[i],k>>i);
        ans+=t;
        k-=t<<i;
    }

    cout<<ans<<'\n';
    return;
    

}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    system("pause");
    return 0;
}
