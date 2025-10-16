#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        map<pair<int,int>,int> mp;
        long long res=0;
        for(int i=n-1;i>=0;i--){
            if(i<n-1){
                if(mp.find({(x-a[i]%x)%x,a[i]%y})!=mp.end()){
                    res+=mp[{(x-a[i]%x)%x,a[i]%y}];
                }
            }
            mp[{a[i]%x,a[i]%y}]++;
        }
        cout<<res<<'\n';


    }
}


