#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        long long ans=0;
        if(k>1){
            sort(a.begin(),a.end(),greater<int>());
            ans=accumulate(a.begin(),a.begin()+k+1,0LL);
        }
        else{
            int l=*max_element(a.begin(),a.end()-1);
            int r=*max_element(a.begin()+1,a.end());
            ans=max(l+a.back(),r+a[0]);

        }
        cout<<ans<<'\n';
    }
    
    return 0;
}