#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int gap=a[1]-a[0];
    
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=gap){
            cout<<"NO"<<'\n';
            return; 
        }
    }


    for(int i=0;i<n;i++){
        a[i]=a[i]+(gap>0?(-gap)*(i+1):gap*(n-i));
    }


    if(a[0]>=0&&a[0]%(n+1)==0) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    
     
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}